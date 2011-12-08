#include "stdio.h" // KSW ++ 2011_02_26
#include "redwood_huffman_decoder.h"

int jpeg_huff_decode (int dc, int tb_idx, int min_bits);

unsigned char *g_jpegBuf;
int g_jpegLen = 0;
int frameLen;
int isError;
int MCU_count;
int errCnt = 0;


int redwood_jpeg_valid_check(char *jpegBuf, int jpegLen)
{
	unsigned char a,b;
	int block;
	int i;

	g_jpegBuf = (unsigned char*)jpegBuf;
	g_jpegLen = jpegLen;
	//printf("jpeg len : %d\n", g_jpegLen);

	for ( i = g_jpegLen - 24; i < g_jpegLen; i++ )
	{
		if ( g_jpegBuf[i] == 0xff )
			if (g_jpegBuf[i+1] == 0xd9 )
				break;
	}
	if ( i == g_jpegLen )
		printf("<<<<<<<<<<<<<<<<<file eof not found>>>>>>>>>>>>>\n");


	frameLen = 0;

	// Skip stream until finding SOS in header
	isError = 0;
	errCnt = 0;
	while(1)
	{
		a = *g_jpegBuf++;
		if(a==0xff) // FF : header marker
		{
			b = *g_jpegBuf++;
			frameLen++;
			if(b==0xc0) { // extract image size information
				for(i=0; i<5; i++)
				{
					*g_jpegBuf++; // read 5 more bytes
					frameLen++;
				}
				if(*g_jpegBuf++==0x05) image_is_HD = 1; // 0x05 0x00 --> 1280 (HD)
				else image_is_HD = 0; // non HD image
				frameLen++;
			}
			if(b==0xda) break; // FFDA : SOS marker
		}
	}
	
	// Read additional info header : always 12 bytes long
	for(i=0; i<12; i++) 
	{
		a = *g_jpegBuf++;
		frameLen++;
	}

	// Initialize
	MCU_count=0;

	// Fill initial data to bit buffer
	for(i=0; i<4; i++)
	{
		bit_tmp = (unsigned int) *g_jpegBuf++;
		frameLen++;
		bit_buf |= (bit_tmp<<(8*(3-i)));
	}

	bits_left=32; no_more_bits = 0;

	// Block decoding loop
	while(!no_more_bits)
	{
		MCU_count++;

		for(block=0; block<6; block++) // 6 blocks (4 Y blocks and 2 UV blocks) in MCU
		{
			if(!no_more_bits) fill_bit_buffer();
			else break;

			// DC decoding
			huff_decode(1,0,block);
			if(!no_more_bits) fill_bit_buffer();
			else break;

			if ( !no_more_bits )
			{
				// AC decoding
				for(i=1; i<64; i++)
				{
					if( !huff_decode(0,&i,block) ) break; // End of block returned
					if(!no_more_bits) fill_bit_buffer();
					else break;
				}
			}
		}

	}
	if ( isError )
	{
		printf("jpeg error: %d\n", errCnt);
		return 0;
	}

	return 1; // no error
}

int huff_decode(int dc, int* cur_ac_pos, int block)
{
	int r,s;
	int* look_nbits; 
	int* look_sym;

	int nb, look, tb_idx;

	tb_idx = (block>3)? 1 : 0; 
	if(dc) { look_nbits = dc_look_nbits[tb_idx]; look_sym = dc_look_sym[tb_idx]; }
	else   { look_nbits = ac_look_nbits[tb_idx]; look_sym = ac_look_sym[tb_idx]; }

	look = PEEK_BITS(8); 
	if ((nb = look_nbits[look]) != 0) { 
		DROP_BITS(nb); 
		s = look_sym[look]; 
		bit_buf <<= nb; // discard decoded bits from buffer
	} 
	else { 
		nb = 9; 
label1: 
		if ((s=jpeg_huff_decode(dc,tb_idx,nb)) < 0) 
		{ return 0; }
	}

	// examine current stream bit by bit to match it to a huffman code
	if(dc) // searching DC Huffman table
	{
		/* Convert DC difference to actual value, update last_dc_val */
		if (s) {
			//r = GET_BITS(s);
			bit_buf <<= s; DROP_BITS(s); // discard decoded bits from buffer
			//s = HUFF_EXTEND(r, s);
		}
		//// detecting DC deviated too much from neighbor DC --> fail
		//if( ((s - last_dc_val[MCU_membership[block]] > 85) || (s - last_dc_val[MCU_membership[block]] < -85)) && block!=0)
		//	printf("Too much change of DC value in %dth MCU\n",MCU_count);
		//s += last_dc_val[MCU_membership[block]];
		//last_dc_val[MCU_membership[block]] = s;
	}
	else // searching AC Huffman table
	{
		r = s >> 4;
		s &= 15;

		if (s) {
			(*cur_ac_pos) += r;
#if !use_scheme1
			r = GET_BITS(s);
#endif
			bit_buf <<= s; DROP_BITS(s); // discard decoded bits from buffer

			////////////////////////// error detection codes start ///////////////////////
			// AC value overflow scheme 1 
			if( (s>8 && (*cur_ac_pos)>= 3) || (s>7 && (*cur_ac_pos)>= 6) || (s>6 && (*cur_ac_pos)>=10) ||
				(s>5 && (*cur_ac_pos)>=15) || (s>4 && (*cur_ac_pos)>=21) || (s>3 && (*cur_ac_pos)>=28) )
			{
				isError = 1;
				errCnt++;
				printf("AC value overflow error detected in %dth MCU\n",MCU_count);
			}

		} else {
			if (r != 15)
				return 0; // End of Block
			(*cur_ac_pos) += 15;
		}
	}

	return 1;
}

void fill_bit_buffer()
{
	unsigned char a;

	while(!(bits_left > 24))
	{
		bit_tmp = (unsigned int) *g_jpegBuf++;
		frameLen++;
		if(bit_tmp==0xff) // header or stuffed 0x00 follows
		{
			if((a=*g_jpegBuf++)==0xd9)
			{	
				no_more_bits = 1;
				break;
				//printf("!!!!!!!!!!!!!!!!!!fileend:%d\n",frameLen);
			}
			frameLen++;
		}
		bit_buf |= ((bit_tmp<<24) >> bits_left);
		bits_left+=8;
		if ( frameLen > g_jpegLen ) 
		{
			printf("frameLen:%d\n", frameLen);
			no_more_bits = 1;
			break;
		}
	}
}

int jpeg_huff_decode (int dc, int tb_idx, int min_bits)
{
	int l = min_bits;
	int code;
	int* maxcode;
	short* huffval;
	int* valoffset;

	if(dc) {
		maxcode = dc_maxcode[tb_idx]; 
		huffval = dc_huffval; 
		valoffset = dc_valoffset[tb_idx]; 
	}
	else {
		maxcode = ac_maxcode[tb_idx]; 
		huffval = ac_huffval[tb_idx]; 
		valoffset = ac_valoffset[tb_idx]; 
	}

	/* HUFF_DECODE has determined that the code is at least min_bits */
	/* bits long, so fetch that many bits in one swoop. */

	code = GET_BITS(l);
	bit_buf <<= l; DROP_BITS(l); // discard the decoded bit from buffer

	/* Collect the rest of the Huffman code one bit at a time. */
	/* This is per Figure F.16 in the JPEG spec. */

	while (code > maxcode[l]) {
		code <<= 1;
		code |= GET_BITS(1);
		bit_buf <<= 1; DROP_BITS(1); // discard the decoded bit from buffer
		l++;
	}

	/* With garbage input we may reach the sentinel value l = 17. */

	if (l > 16) {
		//printf("Error : Impossible Huffman code length!:%d\n",l);
		return 0;			/* fake a zero as the safest result */
	}

	return huffval[ (int) (code + valoffset[l]) ];
}

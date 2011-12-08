
/*!
 ***************************************************************************
 * \file vlc.c
 *
 * \brief
 *    (CA)VLC coding functions
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *    - Inge Lille-Langøy               <inge.lille-langoy@telenor.com>
 *    - Detlev Marpe                    <marpe@hhi.de>
 *    - Stephan Wenger                  <stewe@cs.tu-berlin.de>
 ***************************************************************************
 */

#include <assert.h>

#include "global.h"
#include "defines.h"
#include "vlc.h"


/*! 
 *************************************************************************************
 * \brief
 *    ue_v, writes an ue(v) syntax element, returns the length in bits
 *
 * \param value
 *    the value to be coded
 *  \param bitstream
 *    the Bitstream the value should be coded into
 *
 * \return
 *    Number of bits used by the coded syntax element
 *
 * \ note
 *    This function writes always the bit buffer for the progressive scan flag, and
 *    should not be used (or should be modified appropriately) for the interlace crap
 *    When used in the context of the Parameter Sets, this is obviously not a
 *    problem.
 *
 *************************************************************************************
 */
//void ue_v (int value)
int  ue_v (int value)
{
  SyntaxElement symbol, *sym=&symbol;
  sym->mapping = ue_linfo;               // Mapping rule: unsigned integer
  sym->value1 = value;

  writeSyntaxElement_UVLC (sym);

  return (sym->len);
}


/*! 
 *************************************************************************************
 * \brief
 *    se_v, writes an se(v) syntax element, returns the length in bits
 *
 * \param value
 *    the value to be coded
 *  \param bitstream
 *    the Bitstream the value should be coded into
 *
 * \return
 *    Number of bits used by the coded syntax element
 *
 * \ note
 *    This function writes always the bit buffer for the progressive scan flag, and
 *    should not be used (or should be modified appropriately) for the interlace crap
 *    When used in the context of the Parameter Sets, this is obviously not a
 *    problem.
 *
 *************************************************************************************
 */
//void se_v (int value)
int se_v (int value)
{
  SyntaxElement symbol, *sym=&symbol;
  sym->mapping = se_linfo;               // Mapping rule: signed integer
  sym->value1 = value;
  
  writeSyntaxElement_UVLC (sym);
  return (sym->len);
}


/*! 
 *************************************************************************************
 * \brief
 *    u_1, writes a flag (u(1) syntax element, returns the length in bits, 
 *    always 1
 *
 * \param value
 *    the value to be coded
 *  \param bitstream
 *    the Bitstream the value should be coded into
 *
 * \return
 *    Number of bits used by the coded syntax element (always 1)
 *
 * \ note
 *    This function writes always the bit buffer for the progressive scan flag, and
 *    should not be used (or should be modified appropriately) for the interlace crap
 *    When used in the context of the Parameter Sets, this is obviously not a
 *    problem.
 *
 *************************************************************************************
 */
//void u_1 (int value)
int u_1 (int value)
{
  SyntaxElement symbol, *sym=&symbol;
  sym->bitpattern = value;
  sym->len = 1;
  sym->value1 = value;

  writeSyntaxElement_fixed(sym);
  return (sym->len);
}


/*! 
 *************************************************************************************
 * \brief
 *    u_v, writes a a n bit fixed length syntax element, returns the length in bits, 
 *
 * \param value
 *    the value to be coded
 *  \param bitstream
 *    the Bitstream the value should be coded into
 *
 * \return
 *    Number of bits used by the coded syntax element 
 *
 * \ note
 *    This function writes always the bit buffer for the progressive scan flag, and
 *    should not be used (or should be modified appropriately) for the interlace crap
 *    When used in the context of the Parameter Sets, this is obviously not a
 *    problem.
 *
 *************************************************************************************
 */

//void u_v (int n, int value)
int u_v (int n, int value)
{
  SyntaxElement symbol, *sym=&symbol;
  sym->bitpattern = value;
  sym->len = n;
  sym->value1 = value;

  writeSyntaxElement_fixed(sym);
  return (sym->len);
}


/*!
 ************************************************************************
 * \brief
 *    mapping for ue(v) syntax elements
 * \param ue
 *    value to be mapped
 * \param info
 *    returns mapped value
 * \param len
 *    returns mapped value length
 ************************************************************************
 */
void ue_linfo(int ue, int *len,int *info)
{
  int i,nn;

  nn=(ue+1)/2;

  for (i=0; i < 16 && nn != 0; i++)
  {
    nn /= 2;
  }
  *len= 2*i + 1;
  *info=ue+1-(int)(1<<i);
}


/*!
 ************************************************************************
 * \brief
 *    mapping for ue(v) syntax elements
 * \param ue
 *    value to be mapped
 * \param info
 *    returns mapped value
 * \param len
 *    returns mapped value length
 ************************************************************************
 */
void se_linfo(int se, int *len,int *info)
{

  int i,n,sign,nn;

  sign=0;

  if (se <= 0)
  {
    sign=1;
  }
  n=absm(se) << 1;

  /*
  n+1 is the number in the code table.  Based on this we find length and info
  */

  nn=n/2;
  for (i=0; i < 16 && nn != 0; i++)
  {
    nn /= 2;
  }
  *len=i*2 + 1;
  *info=n - (int)(1<<i) + sign;
}

/*!
 ************************************************************************
 * \brief
 *    Makes code word and passes it back
 *    A code word has the following format: 0 0 0 ... 1 Xn ...X2 X1 X0.
 *
 * \par Input:
 *    Info   : Xn..X2 X1 X0                                             \n
 *    Length : Total number of bits in the codeword
 ************************************************************************
 */
 // NOTE this function is called with sym->inf > (1<<(sym->len/2)).  The upper bits of inf are junk
int symbol2uvlc(SyntaxElement *sym)
{
  int suffix_len=sym->len/2;  
  sym->bitpattern = (1<<suffix_len)|(sym->inf&((1<<suffix_len)-1));
  return 0;
}


/*!
 ************************************************************************
 * \brief
 *    generates UVLC code and passes the codeword to the buffer
 ************************************************************************
 */
void writeSyntaxElement_UVLC(SyntaxElement *se)
{
  se->mapping(se->value1,&(se->len),&(se->inf));
  symbol2uvlc(se);

  writeUVLC2buffer(se);
}


/*!
 ************************************************************************
 * \brief
 *    passes the fixed codeword to the buffer
 ************************************************************************
 */
void writeSyntaxElement_fixed(SyntaxElement *se)
{  
  writeUVLC2buffer(se);
}



/*!
 ************************************************************************
 * \brief
 *    generates UVLC code and passes the codeword to the buffer
 * \author
 *  Tian Dong
 ************************************************************************
 */
void writeSyntaxElement2Buf_UVLC(SyntaxElement *se)
{

  se->mapping(se->value1,&(se->len),&(se->inf));

  symbol2uvlc(se);

  writeUVLC2buffer(se);
}


/*!
 ************************************************************************
 * \brief
 *    writes UVLC code to the appropriate buffer
 ************************************************************************
 */
void  writeUVLC2buffer(SyntaxElement *se)
{
  OutputStreamController(se->bitpattern,se->len);	// OSC Model by Jerry
//  printf("OSC : pattern[0x%X], len[%d]\n", se->bitpattern, se->len);
}

void OutputStreamController(int info, int length)
{
  // OSC hardware
  //MSG(MSG_OSC_OUT);
  //MSGX(0x1|(length<<1)|(info<<6));
  OSCCR0 = (0x1|(length<<1)|(info<<6));
  
  bits_to_go -= (length&0x7);
  if(bits_to_go <= 0)
          bits_to_go += 8; 
//  for (i=0; i<length; i++)
//  {
//  	bits_to_go--;
//	if(bits_to_go==0)
//		bits_to_go = 8;
//  }
}


/*!
 ************************************************************************
 * \brief
 *    generates UVLC code and passes the codeword to the buffer
 * \author
 *  Tian Dong
 ************************************************************************
 */
void writeSyntaxElement2Buf_Fixed(SyntaxElement *se)
{
  writeUVLC2buffer(se);
}


/*!
 ************************************************************************
 * \brief
 *    Makes code word and passes it back
 *
 * \par Input:
 *    Info   : Xn..X2 X1 X0                                             \n
 *    Length : Total number of bits in the codeword
 ************************************************************************
 */

int symbol2vlc(SyntaxElement *sym)
{
  int info_len = sym->len;

  // Convert info into a bitpattern int
  sym->bitpattern = 0;

  // vlc coding
  while(--info_len >= 0)
  {
    sym->bitpattern <<= 1;
    sym->bitpattern |= (0x01 & (sym->inf >> info_len));
  }
  return 0;
}


/*!
 ************************************************************************
 * \brief
 *    generates VLC code and passes the codeword to the buffer
 ************************************************************************
 */
void writeSyntaxElement_VLC(SyntaxElement *se)
{
  se->inf = se->value1;
  se->len = se->value2;
  symbol2vlc(se);

  writeUVLC2buffer(se);
}


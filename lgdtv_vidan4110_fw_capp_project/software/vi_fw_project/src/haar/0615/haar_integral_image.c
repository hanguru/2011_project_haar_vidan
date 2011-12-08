//
// 
// (c) 2011 Brian Fransioli, CAPP Lab

#include "haar_define.h"
//#include "msg.h"


// for debugging
extern int my_frame_num;
#include "global.h"

//Haar_Image *
void
integral_image_new(Haar_Image *image, Haar_Image *integral_image)
{
	int x, y;
	int src_height, integral_height;
	int src_width, integral_width; 

    // openrisc 1200 is Big endian 
    // so, no need for endian change to access image data
    int endian_change = 0;
	int x_tmp;

	//Image *integral_image = (Image *) INTEGRAL_IMAGE_MEMORY_ADDR;
	//Haar_Image *integral_image;

	// Assume source data from Grayscale 8bit image
	unsigned char *src_data;

	// Integral image with uint precision
	unsigned int *dst_data;
	
	src_width = image->width;
	src_height = image->height;
	integral_width =  integral_image->width;
	integral_height = integral_image->height;

	//SET_MEMORY(integral_image, Haar_Image, INTEGRAL_IMAGE_MEMORY_OFFSET);
	//SET_MEMORY(integral_image->data, void, INTEGRAL_IMAGE_DATA_MEMORY_OFFSET);
	//integral_image->width = width;
	//integral_image->height = height;

	src_data = (unsigned char *)image->data;
	dst_data = (unsigned int *)integral_image->data;

	// Initialize elements of first (y = 0) row with their initial column values
	y = 0;
	for (x = 0; x < integral_width; x++) {
		x_tmp = endian_change ? x + 3 - 2*(x&0x3) : x;
		//dst_data[ y * integral_width + x ] = src_data[ y * src_width + x_tmp  ];
		*((unsigned int *)(my_c2_addr_gen((int)(dst_data + y * integral_width + x )))) = *((unsigned char *)(my_c2_addr_gen((int)(src_data + y * src_width + x_tmp  ))));
	}
    //MSG(ONE);
    
	// Cumulatively sum the first row to get integral image values for first row
	for (x = 1; x < integral_width; x++) {
		//dst_data[ y * integral_width + x ] += dst_data[ y * integral_width + (x-1) ];
		*((unsigned int *)(my_c2_addr_gen((int)(dst_data + y * integral_width + x )))) += *((unsigned int *)(my_c2_addr_gen((int)(dst_data + y * integral_width + (x-1) ))));
	}
    //MSG(TWO);

	// Initialize elements of first (x = 0) column with their initial row values
	x = 0;
	for (y = 1; y < integral_height; y++) {
		x_tmp = endian_change ? x + 3 - 2*(x&0x3) : x;
		//dst_data[ y * integral_width + x ] = src_data[ y * src_width + x_tmp  ];
		*((unsigned int *)(my_c2_addr_gen((int)(dst_data + y * integral_width + x )))) = *((unsigned char *)(my_c2_addr_gen((int)(src_data + y * src_width + x_tmp  ))));
	}
    //MSG(THREE);

	// Cumulatively sum the first column to get integral image values for first column
	for (y = 1; y < integral_height; y++) {
		//dst_data[ y * integral_width + x ] += dst_data[ (y-1) * integral_width + x ];
		*((unsigned int *)(my_c2_addr_gen((int)(dst_data + y * integral_width + x )))) += *((unsigned int *)(my_c2_addr_gen((int)(dst_data + (y-1) * integral_width + x ))));
	}
    //MSG(FOUR);

	// Perform integral image process on the remaining part of the image (from 1,1)
	//for (y = 1; y < 60; y++) {
	for (y = 1; y < integral_height; y++) {

		//for (x = 1; x < integral_width; x++) {
		for (x = 1; x < integral_width; x++) {

			// Copy the source value into the empty destination element
		    x_tmp = endian_change ? x + 3 - 2*(x&0x3) : x;
			//dst_data[ y * integral_width + x ] = src_data[ y * src_width + x_tmp ];
			*((unsigned int *)(my_c2_addr_gen((int)(dst_data + y * integral_width + x )))) = *((unsigned char *)(my_c2_addr_gen((int)(src_data + y * src_width + x_tmp ))));

			// Add the element to the left
			//dst_data[ y * integral_width + x ] += dst_data[ y * integral_width + (x-1) ];
			*((unsigned int *)(my_c2_addr_gen((int)(dst_data + y * integral_width + x )))) += *((unsigned int *)(my_c2_addr_gen((int)(dst_data + y * integral_width + (x-1) ))));

			// Add the element above
			//dst_data[ y * integral_width + x ] += dst_data[ (y-1) * integral_width + x ];
			*((unsigned int *)(my_c2_addr_gen((int)(dst_data + y * integral_width + x )))) += *((unsigned int *)(my_c2_addr_gen((int)(dst_data + (y-1) * integral_width + x ))));

			// Subtract the adjacent top left corner element - preserving integral image properties
			//dst_data[ y * integral_width + x ] -= dst_data[ (y-1) * integral_width + (x-1) ];
			*((unsigned int *)(my_c2_addr_gen((int)(dst_data + y * integral_width + x )))) -= *((unsigned int *)(my_c2_addr_gen((int)(dst_data + (y-1) * integral_width + (x-1) ))));

		}

        //MSG(FIVE);

	}
/*
	// for debugging only
	for (y = integral_height*3/4; y < integral_height; y++) {

		//for (x = 1; x < integral_width; x++) {
		for (x = integral_width*3/4; x < integral_width; x++) {

			// Copy the source value into the empty destination element
		    x_tmp = endian_change ? x + 3 - 2*(x&0x3) : x;
			//dst_data[ y * integral_width + x ] = src_data[ y * src_width + x_tmp ];
	*((unsigned char *)(my_c2_addr_gen((int)(src_data + y * src_width + x_tmp )))) = *((unsigned int *)(my_c2_addr_gen((int)(dst_data + y * integral_width + x ))));
		}
	}
*/

/*
		// for debugging test 
		int src_frame_width = (ORC_CAM_SIZE & 0xffff);
		if ( my_frame_num%3 == 0 ) 
		{
			if ( (int)src_data == 0xF0000000 ) 
				haar_draw_rect (0xF0000000, src_frame_width, 50, 50, 50, 50, 255, 0);
			else 
				haar_draw_rect (0XF0000000, src_frame_width, 50, 50, 50, 50, 255, 1);
		}
		else if ( my_frame_num%3 == 1 ) 
		{
			if ( (int)src_data == 0xF0200000 )
				haar_draw_rect (0xF0200000, src_frame_width, 100, 50, 50, 50, 255, 0);
			else {
				//haar_draw_rect (0xF0200000, src_frame_width, 100, 50, 50, 50, 255, 1);
			    if ( (int)src_data == 0xF0000000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 100, 50, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0100000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 150, 100, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0300000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 200, 150, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0400000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 250, 200, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0500000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 300, 250, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0600000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 350, 300, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0700000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 400, 350, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0800000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 450, 400, 50, 50, 255, 1);
			}
		}
		else if ( my_frame_num%3 == 2 ) 
		{
			if ( (int)src_data == 0xF0400000 ) 
				haar_draw_rect (0XF0400000, src_frame_width, 150, 50, 50, 50, 255, 0);
			else {
				//haar_draw_rect (0XF0400000, src_frame_width, 150, 50, 50, 50, 255, 1);
			    if ( (int)src_data == 0xF0000000 )
    				haar_draw_rect ((0xF0400000), (ORC_CAM_SIZE & 0xffff), 200, 100, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0100000 )
    				haar_draw_rect ((0xF0400000), (ORC_CAM_SIZE & 0xffff), 250, 150, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0300000 )                                    
    				haar_draw_rect ((0xF0400000), (ORC_CAM_SIZE & 0xffff), 300, 200, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0400000 )                                    
    				haar_draw_rect ((0xF0400000), (ORC_CAM_SIZE & 0xffff), 350, 250, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0500000 )                                 
    				haar_draw_rect ((0xF0400000), (ORC_CAM_SIZE & 0xffff), 400, 300, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0600000 )                                 
    				haar_draw_rect ((0xF0400000), (ORC_CAM_SIZE & 0xffff), 450, 350, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0700000 )                              
    				haar_draw_rect ((0xF0400000), (ORC_CAM_SIZE & 0xffff), 500, 400, 50, 50, 255, 1);
			    else if ( (int)src_data == 0xF0800000 )
    				haar_draw_rect ((0xF0400000), (ORC_CAM_SIZE & 0xffff), 550, 450, 50, 50, 255, 1);
			}
		}
*/
	//return(integral_image);
	return;
}

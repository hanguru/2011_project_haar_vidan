
/*!
 ************************************************************************
 * \file image.h
 *
 * \author
 *  Inge Lille-Langøy               <inge.lille-langoy@telenor.com>
 *  Copyright (C) 1999  Telenor Satellite Services, Norway
 ************************************************************************
 */
#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "mbuffer.h"

//extern StorablePicture *enc_picture;
//extern StorablePicture *enc_frame_picture;

void encode_one_frame (void);
//int encode_one_frame (void);

void init_offset (void);
//void get_block(int ref_frame, StorablePicture **list, int x_pos, int y_pos, int block[BLOCK_SIZE][BLOCK_SIZE]);
#endif


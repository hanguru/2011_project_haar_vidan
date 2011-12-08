
/*!
 ***********************************************************************
 *  \file
 *      mbuffer.h
 *
 *  \brief
 *      Frame buffer functions
 *
 *  \author
 *      Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Karsten Sühring          <suehring@hhi.de>
 ***********************************************************************
 */
#ifndef _MBUFFER_H_
#define _MBUFFER_H_

#include "global.h"

//! definition a picture (field or frame)
//typedef struct storable_picture
//{
//  int         pic_num;
//  
//  int         size_x, size_y, size_x_cr, size_y_cr;
//  
//  int  ***    ref_idx;       //<! reference picture   [list][subblock_x][subblock_y]
//
//// For ADF fucntions:modified by chae 2006.06.23
//  int  ***    mv;            //<! motion vector       [2line:upper/curr][subblock_x][x/y]
//  //int *** curr_mv;   //[4][subblock_x][x/y]
//  //int *** upper_mv;  //[4][subblock_x][x/y]
//  //int * left_mv;
//
//} StorablePicture;


extern int listXsize;

//StorablePicture* alloc_storable_picture(int size_x, int size_y, int size_x_cr, int size_y_cr);
//void             free_storable_picture(StorablePicture* p);

void             init_lists(int currSliceType);

#endif


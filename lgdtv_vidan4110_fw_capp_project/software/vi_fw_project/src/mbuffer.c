
/*!
 ***********************************************************************
 *  \file
 *      mbuffer.c
 *
 *  \brief
 *      Frame buffer functions
 *
 *  \author
 *      Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Karsten Sühring          <suehring@hhi.de>
 ***********************************************************************
 */

#include <assert.h>

#include "global.h"
#include "mbuffer.h"
#include "memalloc.h"
#include "image.h"
#include "tube.h"

//-------- start new Buffer code -----------------------------
int listXsize;

/*!
 ************************************************************************
 * \brief
 *    Allocate memory for a stored picture. 
 *
 * \param size_x
 *    horizontal luma size
 * \param size_y
 *    vertical luma size
 * \param size_x_cr
 *    horizontal chroma size
 * \param size_y_cr
 *    vertical chroma size
 *
 * \return
 *    the allocated StorablePicture structure
 ************************************************************************
 */
//StorablePicture* alloc_storable_picture(int size_x, int size_y, int size_x_cr, int size_y_cr)
//{
//  StorablePicture *s;
//
//  tube_print("malloc alloc_storable_picture\n");
//  TUBE_0_PRINT_WORD(sizeof(StorablePicture));
//  s = malloc (sizeof(StorablePicture));
//  TUBE_0_PRINT_WORD(s);
//  if (NULL==s) 
//    no_mem_exit("alloc_storable_picture: s");
////temporally modified by eskim to reduce the size of used memory
// //0108
// // get_mem3Dint (&(s->mv), size_x / BLOCK_SIZE, size_y / BLOCK_SIZE, 2);
//s->mv = 0;
//  //added by chae 12.21
//  //get_mem3Dint (&(s->ref_idx), 1, size_x / BLOCK_SIZE, size_y / BLOCK_SIZE);
// /*
//  //only 2 line - upper line, curr line
//  get_mem3Dint (&(s->curr_mv),  BLOCK_SIZE,  size_x / BLOCK_SIZE,  2);
//  get_mem3Dint (&(s->upper_mv), BLOCK_SIZE,  size_x / BLOCK_SIZE,  2);
//  get_mem3Dint (&(s->ref_idx), 1, size_x / BLOCK_SIZE, size_y / BLOCK_SIZE);
//*/
//  s->size_x = size_x;
//  s->size_y = size_y;
//  s->size_x_cr = size_x_cr;
//  s->size_y_cr = size_y_cr;
//  
//  s->pic_num = 0;
////  s->frame   = NULL;
//
//  MSG(ALLOC_STORABLE_PICTURE);
//
//  return s;
//
////	return NULL;
//
//}

/*!
 ************************************************************************
 * \brief
 *    Free picture memory.
 *
 * \param p
 *    Picture to be freed
 *
 ************************************************************************
 */
//void free_storable_picture(StorablePicture* p)
//{
//  if (p)
//  {
//    free_mem3Dint (p->mv,      p->size_x / BLOCK_SIZE);
//    //free_mem3Dint (p->curr_mv ,     BLOCK_SIZE);
//    //free_mem3Dint (p->upper_mv ,    BLOCK_SIZE);
//    //free_mem3Dint (p->ref_idx, 1);
//    free(p);
//  }
//
//  MSG(FREE_STORABLE_PICTURE);
//}


/*!
 ************************************************************************
 * \brief
 *    Initilaize listX[0] and list 1 depending on current picture type
 *
 ************************************************************************
 */
void init_lists(int currSliceType)
{
  if (currSliceType == I_SLICE)
  {
	listXsize = 0;
    return;
  }
  // set max size
  listXsize = 1; 
} 


//-------- end new Buffer code -----------------------------


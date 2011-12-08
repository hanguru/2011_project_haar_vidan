
/*!
 *************************************************************************************
 * \file mb_access.c
 *
 * \brief
 *    Functions for macroblock neighborhoods
 *
 *  \author
 *      Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Karsten Sühring          <suehring@hhi.de>
 *************************************************************************************
 */

#include "global.h"

/*!
 ************************************************************************
 * \brief
 *    returns 1 if the macroblock at the given address is available
 ************************************************************************
 */
int mb_is_available(int mbAddr)
{
  if ((mbAddr < 0) || (mbAddr > ((int)img.PicSizeInMbs - 1)))
    return 0;

  return 1;
}

/*!
 ************************************************************************
 * \brief
 *    Checks the availability of neighboring macroblocks of
 *    the current macroblock for prediction and context determination;
 ************************************************************************
 */
void CheckAvailabilityOfNeighbors()
{
  const int mb_nr = img.current_mb_nr;
  const int PicWidthInMbs = img.PicWidthInMbs;
//  Macroblock *currMB = &img.mb_data[mb_nr];
  Macroblock *currMB = &img.mb_data_q;

  currMB->mbAddrA = mb_nr - 1;
  currMB->mbAddrB = mb_nr - img.PicWidthInMbs;
  //currMB->mbAddrC = mb_nr - img.PicWidthInMbs + 1;
  //currMB->mbAddrD = mb_nr - img.PicWidthInMbs - 1;

  currMB->mbAvailA = mb_is_available(currMB->mbAddrA) && ((mb_nr % PicWidthInMbs)!=0);
  currMB->mbAvailB = mb_is_available(currMB->mbAddrB);
  //currMB->mbAvailC = mb_is_available(currMB->mbAddrC) && (((mb_nr+1) % PicWidthInMbs)!=0);
  //currMB->mbAvailD = mb_is_available(currMB->mbAddrD) && ((mb_nr % PicWidthInMbs)!=0);
}


/*!
 ************************************************************************
 * \brief
 *    returns the x and y macroblock coordinates for a given MbAddress
 ************************************************************************
 */
void get_mb_block_pos (int mb_addr, int *x, int*y)
{
    *x = (mb_addr % img.PicWidthInMbs);
    *y = (mb_addr / img.PicWidthInMbs);
}

/*!
 ************************************************************************
 * \brief
 *    returns the x and y sample coordinates for a given MbAddress
 ************************************************************************
 */
void get_mb_pos (int mb_addr, int *x, int*y)
{
  get_mb_block_pos(mb_addr, x, y);
  
  (*x) *= MB_BLOCK_SIZE;
  (*y) *= MB_BLOCK_SIZE;
}


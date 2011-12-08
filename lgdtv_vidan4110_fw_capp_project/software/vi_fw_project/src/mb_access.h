
/*!
 *************************************************************************************
 * \file mb_access.h
 *
 * \brief
 *    Functions for macroblock neighborhoods
 *
 * \author
 *     Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Karsten Sühring          <suehring@hhi.de>
 *************************************************************************************
 */

#ifndef _MB_ACCESS_H_
#define _MB_ACCESS_H_

void CheckAvailabilityOfNeighbors(void);

int  mb_is_available(int mbAddr);
void get_mb_pos (int mb_addr, int *x, int*y);
void get_mb_block_pos (int mb_addr, int *x, int*y);



#endif

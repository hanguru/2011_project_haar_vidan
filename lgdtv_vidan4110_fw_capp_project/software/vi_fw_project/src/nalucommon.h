
/*!
 **************************************************************************************
 * \file
 *    nalucommon.h.h
 * \brief
 *    NALU handling common to encoder and decoder
 *  \date 25 November 2002
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details) 
 *      - Stephan Wenger        <stewe@cs.tu-berlin.de>
 ***************************************************************************************
 */


#ifndef _NALUCOMMON_H_
#define _NALUCOMMON_H_

#define NALU_TYPE_IDR      5
#define NALU_TYPE_SPS      7
#define NALU_TYPE_PPS      8
#define NALU_PRIORITY_HIGHEST     3

//added by eskim as what jjs said for another decoder to decode result stream, such as JM11 and GOM player 
#define NALU_TYPE_SLICE     1
#define NALU_PRIORITY_HIGH 2

#endif

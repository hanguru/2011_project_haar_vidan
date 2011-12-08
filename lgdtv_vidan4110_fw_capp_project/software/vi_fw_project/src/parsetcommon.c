
/*!
 **************************************************************************************
 * \file
 *    parset.c
 * \brief
 *    Picture and Sequence Parameter set generation and handling
 *  \date 25 November 2002
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details) 
 *      - Stephan Wenger        <stewe@cs.tu-berlin.de>
 *
 **************************************************************************************
 */
//#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "parsetcommon.h"
#include "memalloc.h"
#include "tube.h"
/*! 
 *************************************************************************************
 * \brief
 *    Allocates memory for a pps
 *
 * \param none
 *
 * \return
 *    pointer to a pps
 *************************************************************************************
 */
 
pic_parameter_set_rbsp_t *AllocPPS ()
{
  pic_parameter_set_rbsp_t *p;

  tube_print("malloc AllocPPS\n");
  //TUBE_0_PRINT_WORD(sizeof (pic_parameter_set_rbsp_t));

  if ((p=malloc (sizeof (pic_parameter_set_rbsp_t))) == NULL)
    no_mem_exit ("AllocPPS: PPS");
  
  //TUBE_0_PRINT_WORD(p);
  
  //MSG(PIC_PARAMETER_SET_RBSP_T);
  return p;
}

 
/*! 
 *************************************************************************************
 * \brief
 *    Allocates memory for am sps
 *
 * \param none
 *
 * \return
 *    pointer to a sps
 *************************************************************************************
 */
 
seq_parameter_set_rbsp_t *AllocSPS ()
{
  seq_parameter_set_rbsp_t *p;

  tube_print("malloc AllocSPS\n");
  //TUBE_0_PRINT_WORD(sizeof (seq_parameter_set_rbsp_t));
  if ((p=malloc (sizeof (seq_parameter_set_rbsp_t))) == NULL)
    no_mem_exit ("AllocSPS: SPS");
  //TUBE_0_PRINT_WORD(p);

  //MSG(SEQ_PARAMETER_SET_RBSP_T);
  return p;
}

 
/*! 
 *************************************************************************************
 * \brief
 *    Frees a pps
 *
 * \param pps to be freed
 *
 * \return
 *    none
 *************************************************************************************
 */
 
 void FreePPS (pic_parameter_set_rbsp_t *pps)
 {
   //assert (pps != NULL);
   if ( pps )
   	free (pps);
 }

 
 /*! 
 *************************************************************************************
 * \brief
 *    Frees a sps
 *
 * \param sps to be freed
 *
 * \return
 *    none
 *************************************************************************************
 */
 
 void FreeSPS (seq_parameter_set_rbsp_t *sps)
 {
   //assert (sps != NULL);
   if ( sps )
   	free (sps); 

   //MSG(FREE_SPS);
 }


/*!
 **************************************************************************************
 * \file
 *    parset.h
 * \brief
 *    Picture and Sequence Parameter Sets, encoder operations
 *    This code reflects JVT version xxx
 *  \date 25 November 2002
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details) 
 *      - Stephan Wenger        <stewe@cs.tu-berlin.de>
 ***************************************************************************************
 */


#ifndef _PARSET_H_
#define _PARSET_H_

#include "parsetcommon.h"

void GenerateParameterSets (void);
void FreeParameterSets (void);

void GenerateHeader (int);

// The following are local helpers, but may come handy in the future, hence public
void FillParameterSetStructures (seq_parameter_set_rbsp_t *sps, pic_parameter_set_rbsp_t *pps);
void GenerateSeq_parameter_set_rbsp (seq_parameter_set_rbsp_t *sps);
void GeneratePic_parameter_set_rbsp (pic_parameter_set_rbsp_t *pps);
void FreeSPS (seq_parameter_set_rbsp_t *sps);
void FreePPS (pic_parameter_set_rbsp_t *pps);
pic_parameter_set_rbsp_t *AllocPPS (void);
seq_parameter_set_rbsp_t *AllocSPS (void);


#endif

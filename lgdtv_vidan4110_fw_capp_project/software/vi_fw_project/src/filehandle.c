
/*!
 **************************************************************************************
 * \file
 *    filehandle.c
 * \brief
 *    Start and terminate sequences
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Thomas Stockhammer            <stockhammer@ei.tum.de>
 *      - Detlev Marpe                  <marpe@hhi.de>
 ***************************************************************************************
 */

#include "global.h"
#include "header.h"
#include "parset.h"

/*!
 ************************************************************************
 * \brief
 *    This function opens the output files and generates the
 *    appropriate sequence header
 ************************************************************************
 */
int start_sequence()
{
  GenerateHeader(NALU_TYPE_SPS);
  GenerateSeq_parameter_set_rbsp (active_sps);
  //MSG(GENERATE_HEADER_SPS);

  GenerateHeader(NALU_TYPE_PPS);
  GeneratePic_parameter_set_rbsp (active_pps);
  //MSG(GENERATE_HEADER_PPS);

  //MSG(START_SEQUENCE);
  return 0;
}


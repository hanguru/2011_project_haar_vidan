#include "map_hif.h"
#include "tube.h"
#include "sdram_control.h"
//#ifdef SIM_USE_SDRAM_16MBx16 { // {{{
//	SDRAMC_CONFIG = 1;
//#else
//	SDRAMC_CONFIG = 0;
//#endif
//	if (SDRAMC_CONFIG != 0) 
//	    //---------------------------------------------------------------------
//	    // SDRAM memory model
//	    // Micron MT48LC2M16A2 (2M x 16 x 4 Banks)
//	    // Speed grade: -7E, CAS latency: 2
//	    // Freq       : 133 MHz
//	    // tRCD: min. 15 ns
//	    // tRAS: min. 37 ns
//	    // tRP : min. 15 ns
//	    // tRFC: min. 66 ns
//	    // tREF: max. 64 ms
//	    //
//	    // TRCD: # of delay cycles for tRCD
//	    // TRAS: # of delay cycles for tRAS 
//	    // TRP : # of delay cycles for tRP
//	    // TRFC: tRFC / (1s / freq.)
//	    // TREF: freq. / 64,000 - 1
//	    //---------------------------------------------------------------------
//
//	    // Freq: 133 MHz
//	    // TRCD: 1
//	    // TRAS: 2
//	    // TRP : 1
//	    // TRFC: 66ns / (1s / 133Mhz) = 8
//	    // TREF: 133Mhz / 64,000 - 1 = 2077
//	    // CAS : 2
//	    SDRAMC_MODE_SET(1,2,1,8,2077,2);
//	} else {
//	    //---------------------------------------------------------------------
//	    // SDRAM memory model
//	    // Micron MT48LC2M32B2 (512K x 32 x 4 Banks)
//	    // Speed grade: -6, CAS latency: 3
//	    // Freq       : 166 MHz
//	    // tRCD: min. 18 ns
//	    // tRAS: min. 42 ns
//	    // tRP : min. 18 ns
//	    // tRFC: min. 60 ns
//	    // tREF: max. 64 ms
//	    //
//	    // TRCD: # of delay cycles for tRCD
//	    // TRAS: # of delay cycles for tRAS 
//	    // TRP : # of delay cycles for tRP
//	    // TRFC: tRFC / (1s / freq.)
//	    // TREF: freq. / 64,000 - 1
//	    //---------------------------------------------------------------------
//
//	    // Freq: 71.4 MHz
//	    // TRCD: 1
//	    // TRAS: 0
//	    // TRP : 1
//	    // TRFC: 60ns / (1s / 71.4Mhz) = 4
//	    // TREF: 71.4Mhz / 64,000 - 1 = 1114
//	    // CAS : 3
//	    //SDRAMC_MODE_SET(1,0,1,4,1114,3);
//
//	    // Freq: 100 MHz
//	    // TRCD: 1
//	    // TRAS: 2
//	    // TRP : 0
//	    // TRFC: 60ns / (1s / 100Mhz) = 6
//	    // TREF: 100Mhz / 64,000 - 1 = 1561
//	    // CAS : 3
//	    //SDRAMC_MODE_SET(1,2,0,6,1561,3);
//
//	    // Freq: 150 MHz
//	    // TRCD: 1
//	    // TRAS: 4
//	    // TRP : 2
//	    // TRFC: 60ns / (1s / 150Mhz) = 9
//	    // TREF: 150Mhz / 64,000 - 1 = 2342
//	    // CAS : 3
//	    //SDRAMC_MODE_SET(1,4,2,9,2342,3);
//
//	    //---------------------------------------------------------------------
//	    // SDRAM memory model
//	    // Micron MT48LC2M32B2 (512K x 32 x 4 Banks)
//	    // Speed grade: -5, CAS latency: 3
//	    // Freq       : 200 MHz
//	    // tRCD: min. 15 ns
//	    // tRAS: min. 38.7 ns
//	    // tRP : min. 15 ns
//	    // tRFC: min. 60 ns
//	    // tREF: max. 64 ms
//	    //---------------------------------------------------------------------
//
//	    // Freq: 200 MHz
//	    // TRCD: 2
//	    // TRAS: 5
//	    // TRP : 2
//	    // TRFC: 60ns / (1s / 200MHz) = 12
//	    // TREF: 200MHz / 64,000 - 1 = 3124
//	    // CAS : 3
//	    SDRAMC_MODE_SET(2,5,2,12,3124,3);
//	} //}}}

void SDRAM_init(void) {
	ORC_EXT_MEM_TYPE_SEL = 1; /* SDRAM */

	SDRAMC_CONFIG = SDRAM_SDRAMC_CONFIG;

	SDRAMC_TRMODE = SDRAM_SDRAMC_TRMODE;

	SDRAMC_MODE_SET(SDRAM_TRCD, SDRAM_TRAS, SDRAM_TRP, SDRAM_TRFC, SDRAM_TREF,
			SDRAM_CL);

	SDRAMC_OPMODE = 1;

	return;
}


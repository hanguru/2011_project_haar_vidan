#ifndef _SDRAM_CONTROL_H_
#define _SDRAM_CONTROL_H_

#define SDRAMC_MODE_SET(_trcd,_tras,_trp,_trfc,_tref,_cas)		\
do {												\
    SDRAMC_CTRL = ((1<<31) | ((_trcd & 0x7)<<25) | ((_tras & 0x7)<<22) |((_trp & 0x7)<<19) | ((_trfc & 0xF)<<15) | ((_tref & 0xFFF)<<3) | (_cas & 0x7)); \
} while (0)

void SDRAM_init(void);

#endif

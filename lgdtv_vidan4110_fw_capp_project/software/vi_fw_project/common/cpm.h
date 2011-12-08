#include "map.h"
#include "map_hif.h" //jykim_080725_cpm_hif_set++
/* =================================================
 *
 *  CPM Module
 *  ----------
 *
 * ================================================= */
extern void cpm_set_reg(unsigned int addr, unsigned int val, unsigned int mask,
		unsigned int loc);

#define CPM_DISCLK_CR             (CPM_BASE_ADDR + (0x0 << 2))
#define CPM_RST_CR                (CPM_BASE_ADDR + (0x1 << 2))
#define CPM_DIVCLK_CR             (CPM_BASE_ADDR + (0x2 << 2))
#define CPM_PLL_CR0               (CPM_BASE_ADDR + (0x3 << 2)) // Lock time
#define CPM_PLL_CR1               (CPM_BASE_ADDR + (0x4 << 2)) // pll divider
#define CPM_PLL_CR2               (CPM_BASE_ADDR + (0x5 << 2)) // bypass, power
/* ======= CPM_DISCLK_CR ======= */
#define set_dis_clk(_x_)          (*(unsigned volatile int *)CPM_DISCLK_CR |= _x_)
#define unset_dis_clk(_x_)        (*(unsigned volatile int *)CPM_DISCLK_CR &= ~(_x_))

/* ======= CPM_RST_CR ======= */
#define rst_deactive(_x_)         (*(unsigned volatile int *)CPM_RST_CR |= _x_)
#define rst_active(_x_)           (*(unsigned volatile int *)CPM_RST_CR &= ~_x_)

/* ======= CPM_DIVCLK_CR ======= */
// Freq. = PLL_OUT / (_div_+1)
#define sys_clk_div(_div_)        cpm_set_reg(CPM_DIVCLK_CR, _div_, 0xF, 0)
#define risc_clk_div(_div_)       cpm_set_reg(CPM_DIVCLK_CR, _div_, 0xF, 4)
#define amba_clk_div(_div_)       cpm_set_reg(CPM_DIVCLK_CR, _div_, 0xF, 8)
#define cam_clk_div(_div_)        cpm_set_reg(CPM_DIVCLK_CR, _div_, 0xF, 12)
#define dramc_clk_div(_div_)      cpm_set_reg(CPM_DIVCLK_CR, _div_, 0xF, 16)

/* ======= CPM_PLL_CR0 ======= */
//#define PLL_LOCK_CNT              0x5BF // more than 50 us //jykim_080725_cpm_hif_set--
#define PLL_LOCK_CNT              PLL_LOCKTIME_VALUE // more than 50 us //jykim_080725_cpm_hif_set++
#define pll_lock_cnt(_x_)         cpm_set_reg(CPM_PLL_CR0, _x_, 0xFFFF, 0)

/* ======= CPM_PLL_CR1 ======= */
#define PLL_INPUT_DIV(_x_)        ((_x_ & 0x3F))
#define PLL_FEEDBACK_DIV(_x_)     ((_x_ & 0xFF) << 6)
#define PLL_OUTPUT_DIV(_x_)       ((_x_ & 0x3) << 14)
#define pll_clk_div(_x_)          cpm_set_reg(CPM_PLL_CR1, _x_, 0xFFFFFFFF, 0)

/* ======= CPM_PLL_CR2 ======= */
#define set_bypass                (*(unsigned volatile int *)CPM_PLL_CR2 |= 0x1)
#define unset_bypass              (*(unsigned volatile int *)CPM_PLL_CR2 &= ~0x1)
#define set_powerdown             (*(unsigned volatile int *)CPM_PLL_CR2 |= 0x2)
#define unset_powerdown           (*(unsigned volatile int *)CPM_PLL_CR2 &= ~0x2)

/* ======= RESET ======= */
#define CPM_RESET_HRESETn         (1<<0)
#define CPM_RESET_01              (1<<1)
#define CPM_RESET_02              (1<<2)
#define CPM_RESET_03              (1<<3)
#define CPM_RESET_04              (1<<4)
#define CPM_RESET_05              (1<<5)
#define CPM_RESET_06              (1<<6)
#define CPM_RESET_07              (1<<7)

/* ======= CLK DISABLE ======= */
#define CPM_SYS_CLK_DIS           (1<<0)
#define CPM_RISC_CLK_DIS          (1<<1)
//#define CPM_HCLKSYS_DIS           (1<<2) // You must not disable this clock
#define CPM_HCLK_DIS              (1<<3)
#define CPM_AMBA_CLK_DIS_02       (1<<4)
#define CPM_AMBA_CLK_DIS_03       (1<<5)
#define CPM_AMBA_CLK_DIS_04       (1<<6)
#define CPM_AMBA_CLK_DIS_05       (1<<7)
#define CPM_AMBA_CLK_DIS_06       (1<<8)
#define CPM_AMBA_CLK_DIS_07       (1<<9)
#define CPM_AMBA_CLK_DIS_08       (1<<10)
#define CPM_AMBA_CLK_DIS_09       (1<<11)
#define CPM_AMBA_CLK_DIS_10       (1<<12)
#define CPM_AMBA_CLK_DIS_11       (1<<13)
#define CPM_AMBA_CLK_DIS_12       (1<<14)
#define CPM_AMBA_CLK_DIS_13       (1<<15)
#define CPM_AMBA_CLK_DIS_14       (1<<16)
#define CPM_AMBA_CLK_DIS_15       (1<<17)
#define CPM_AMBA_CLK_DIS_16       (1<<18)
#define CPM_AMBA_CLK_DIS_17       (1<<19)
#define CPM_AMBA_CLK_DIS_18       (1<<20)
#define CPM_AMBA_CLK_DIS_19       (1<<21)
#define CPM_AMBA_CLK_DIS_20       (1<<22)
#define CPM_AMBA_CLK_DIS_21       (1<<23)
#define CPM_AMBA_CLK_DIS_22       (1<<24)
#define CPM_AMBA_CLK_DIS_23       (1<<25)
#define CPM_AMBA_CLK_DIS_24       (1<<26)
#define CPM_AMBA_CLK_DIS_25       (1<<27)
#define CPM_AMBA_CLK_DIS_26       (1<<28)
#define CPM_AMBA_CLK_DIS_27       (1<<29)
#define CPM_AMBA_CLK_DIS_28       (1<<30)
#define CPM_CAM_CLK_DIS           (1<<31)

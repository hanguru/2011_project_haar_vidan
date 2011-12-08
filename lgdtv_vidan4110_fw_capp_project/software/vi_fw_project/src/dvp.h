// constant for DVP registers
// jarre 2008.04.18 dvp +

// register map
// Address Read/Write Name
// 0x00        RW     DVP_REG0    
// 0x04        RW     DVP_REG1    
// 0x08        RW     DVP_REG2    
// 0x0C        RW     INIT_Y_ADDR 
// 0x10        RW     INIT_U_ADDR 
// 0x14        RW     INIT_V_ADDR 
// 0x18        RW     FINAL_Y_ADDR
// 0x1C        RW     FINAL_U_ADDR
// 0x20        RW     FINAL_V_ADDR
// 0x24        RW     FRAME_OFFSET
// 0x80        R      DVP_STATUS

// DVP_STATUS [31:2]  RESERVED
//            [1]     DVP_ISP_DONE
//            [0]     DVP_COMP_DONE

// DVP_REG2   [31:9]  RESERVED
//            [8]     MULTI_FRAMES   0: vovsync event for only first frame,
//                                   1: vovsync event for every frames.
//            [7:2]   RESERVED
//            [1]     FRS_ST         1 after 0: DVP ISP lite start.
//            [0]     COMPRESS_ST    1 after 0: DVP compress start.
//
// DVP_REG1   [31]    CONT_CLOCK     0: Qualified VOCLK, 1: Continuous VOCLK.
//            [30:28] RESERVED
//            [27:26] CLOCK_DIV      00: 1/1, 01: 1/2, 10: 1/4, 11: 1/6.
//            [25:24] COMP_MODE      00: mode1, 01: mode2, 10: mode3.
//            [23:16] HPC            VOHSYNC pause cycle on comp mode2.
//            [15:11] VSYNC_SIZE     VSYNC size x 520 VOCLK.
//            [10]    VSYNC_POL      0: Active high VSYNC, 1: Active low VSYNC.
//            [9]     HREF_POL       0: Active high HREF, 1: Active low HREF.
//            [8]     CLOCK_POL      0: Active high PCLK, 1: Active low PCLK.
//            [7]     RGB_FORMAT     0: RGB, 1:BGR.
//            [6:5]   YUV_FORMAT     00: YUYV, 01: UYVY, 10: YVYU, 11: VYUY.
//            [4:2]   IMAGE_FORMAT   000: YUV420, 001: YUV422, 010: RGB444, 011: RGB565.
//            [1:0]   DVP_MODE       00: Frame sram mode(ISP), 11: compression mode.
//
// DVP_REG0   [31:24] VOP_HEIGHT     Image height, macroblock unit.
//            [23:16] VOP_WIDTH      Image width, macroblock unit.
//            [15:0]  CMODE2_SKIPN   Packet size on comp mode2.


#ifndef __DVP_H__
#define __DVP_H__

// REG2
#define DVP_MULTI_FRAMES           0x00000100
#define DVP_FRS_ST                 0x00000002
#define DVP_COMPRESS_ST            0x00000001

// REG1
#define DVP_CONT_CLOCK             0x80000000
#define DVP_PCLK_1_1               0x00000000
#define DVP_PCLK_1_2               0x04000000
#define DVP_PCLK_1_4               0x08000000
#define DVP_PCLK_1_6               0x0C000000
#define DVP_COMP_MODE_1            0x00000000
#define DVP_COMP_MODE_2            0x01000000
#define DVP_COMP_MODE_3            0x02000000
#define DVP_HREF_PAUSE_CYCLE_lsb   16
#define DVP_HREF_PAUSE_CYCLE_fld   0x00FF0000
#define DVP_VSYNC_SIZE_lsb         11
#define DVP_VSYNC_SIZE_fld         0x0000F800
#define DVP_ACTIVE_HIGH_VSYNC      0x00000000
#define DVP_ACTIVE_LOW_VSYNC       0x00000400
#define DVP_ACTIVE_HIGH_HREF       0x00000000
#define DVP_ACTIVE_LOW_HREF        0x00000200
#define DVP_ACTIVE_HIGH_PCLK       0x00000000
#define DVP_ACTIVE_LOW_PCLK        0x00000100
#define DVP_RGB444                 0x00000008
#define DVP_BGR444                 0x00000088
#define DVP_RGB565                 0x0000000C
#define DVP_BGR565                 0x0000008C
#define DVP_YUYV422                0x00000004
#define DVP_UYVY422                0x00000024
#define DVP_YVYU422                0x00000044
#define DVP_VYUY422                0x00000064
#define DVP_YUYV420                0x00000000
#define DVP_UYVY420                0x00000020
#define DVP_YVYU420                0x00000040
#define DVP_VYUY420                0x00000060
#define DVP_FRS_MODE               0x00000000
#define DVP_COMPRESS_MODE          0x00000003

// REG0
#define DVP_HD                     0x2D500000
#define DVP_VGA                    0x1E280000
#define DVP_COMP2_PKT_SIZE_fld     0x0000FFFF

#endif

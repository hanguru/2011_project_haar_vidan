# #################################################
# Definitions
# #################################################

TOP_DIR=$(shell pwd)/$(DEP)
#TOP_DIR=$(DEP)

-include $(TOP_DIR)/user.mk

# #################################################
# Set GLOBAL_DEFINES
# #################################################
# {{{
# ======= Default define ======= #
$(warning >>> VIM BURST READ ENABLED)
GLOBAL_DEFINES+=VIM_BURST_SUPPORT=1
$(warning >>> ADF BURST MODE ENABLED)
GLOBAL_DEFINES+=ADF_BURST_SUPPORT=1
$(warning >>> Use customized HBURST signals [WORKAROUND])
GLOBAL_DEFINES+=H264E_WA_USE_CUSTOMIZED_HBURST=1
GLOBAL_DEFINES+=VIM_BURST_SUPPORT=1
GLOBAL_DEFINES+=CAM_BURST16_MODE=1
GLOBAL_DEFINES+=ADF_BURST_SUPPORT=1
GLOBAL_DEFINES+=ISP_HW_REMOVE=1
#GLOBAL_DEFINES+=USE_DOUBLE_SDRAMC=1

ifndef TARGET
$(error >>> You should define the type of TARGET. You can refer the file in the $(TOP_DIR)/facility)
endif

ifeq ($(findstring X4,$(TARGET)),X4)
GLOBAL_DEFINES+=H264E_CLK_30MHZ=1
GLOBAL_DEFINES+=H264E_MAX_VGA=1
GLOBAL_DEFINES+=H264E_WA_USE_SELECT_RAM=1
$(warning >>> Select RAM used in ISP module [WORKAROUND] )
#	ifdef SIM_MODE_HD
#$(error >>> HD frame size is NOT supported in Virtex 4)
#	endif
endif

# VIRTEX 5 (X5_330)
ifeq ($(TARGET),X5_330)
GLOBAL_DEFINES+=FPGA_VIRTEX5=1
GLOBAL_DEFINES+=FPGA_TARGET=1
endif

ifeq ($(TARGET),MPW)
GLOBAL_DEFINES+=MPW_TARGET=1
$(warning >>> FLASH BOOT ENABLED)
endif

ifeq ($(CPU),OR1200)
GLOBAL_DEFINES+=OR1200=1
$(warning >>> OR1200 is implemented)
endif

ifeq ($(CPU),BA22)
GLOBAL_DEFINES+=BA22=1
$(warning >>> BA22 is implemented)
endif

ifdef BA22_SYNTH
$(error >>> BA22_SYNTH should not be defined at user.mk)
#GLOBAL_DEFINES+=BA22_SYNTH=1
endif

# #################################################
# Chip verson set
# #################################################
# {{{
ifeq ($(CHIP_VER),4100)
$(warning >>> Chip version 4100.)
GLOBAL_DEFINES+=VIDAN4100=1
endif
ifeq ($(CHIP_VER),4110)
$(warning >>> Chip version 4110.)
GLOBAL_DEFINES+=VIDAN4110=1
endif
# }}}

ifdef SIM_MODE_HD
$(error >>> SIM_MODE_HD is not used any more)
#$(warning >>> SIMULATION MODE: HD)
#GLOBAL_DEFINES+=SIM_MODE_HD=1
#else
endif

ifdef SIM_MODE_VGA
$(error >>> SIM_MODE_VGA is not used any more)
#$(warning >>> SIMULATION MODE: VGA)
#GLOBAL_DEFINES+=SIM_MODE_VGA=1
#else
#$(warning >>> SIMULATION MODE: QCIF [DEFAULT])
#endif
endif

#ifdef H264E_SXGA_TO_VGA
#	ifndef SIM_MODE_VGA
#$(error >>> H264E_SXGA_TO_VGA cannot be defined without defining SIM_MODE_VGA)
#	else
#$(warning >>> CAM SIZE: SXGA)
#GLOBAL_DEFINES+=H264E_SXGA_TO_VGA=1
#	endif
#endif

#ifdef SC_BURST16_MODE
GLOBAL_DEFINES+=SC_BURST16_MODE=1
$(warning >>> SCALER BURST16 MODE)
#else
#$(warning >>> SCALER SINGLE MODE)
#endif

ifdef USE_ISP
GLOBAL_DEFINES+=USE_ISP=1
$(warning >>> SIMULATION INPUT: ISP MODEL)
else
$(warning >>> SIMULATION INPUT: CAMERA MODEL [DEFAULT])
endif

ifdef CAM_13
GLOBAL_DEFINES+=CAM_13=1
$(warning >>> SIMULATION INPUT: 1.3-1280x1024)
endif

ifdef CAM_SXGA
GLOBAL_DEFINES+=CAM_SXGA=1
$(warning >>> SIMULATION INPUT: CAM_SXGA-1280x960)
endif

ifdef CAM_WXGA
GLOBAL_DEFINES+=CAM_WXGA=1
$(warning >>> SIMULATION INPUT: CAM_WXGA-1280x800)
endif

ifdef CAM_XGA
GLOBAL_DEFINES+=CAM_XGA=1
$(warning >>> SIMULATION INPUT: CAM_XGA-1024x768)
endif

ifdef CAM_HD
GLOBAL_DEFINES+=CAM_HD=1
$(warning >>> SIMULATION INPUT: CAM_HD-1280x720)
endif

ifdef CAM_SVGA
GLOBAL_DEFINES+=CAM_SVGA=1
$(warning >>> SIMULATION INPUT: CAM_SVGA-800x600)
endif

ifdef CAM_D1
GLOBAL_DEFINES+=CAM_D1=1
$(warning >>> SIMULATION INPUT: CAM_D1-720x480)
endif

ifdef CAM_VGA
GLOBAL_DEFINES+=CAM_VGA=1
$(warning >>> SIMULATION INPUT: CAM_VGA-640x480)
endif

ifdef CAM_CIF
GLOBAL_DEFINES+=CAM_CIF=1
$(warning >>> SIMULATION INPUT: CAM_CIF-352x288)
endif

ifdef CAM_QCIF
GLOBAL_DEFINES+=CAM_QCIF=1
$(warning >>> SIMULATION INPUT: CAM_QCIF-176x144)
endif

ifdef USER_HW_TOP_TB_DEF
GLOBAL_DEFINES+=USER_HW_TOP_TB_DEF=1
$(warning >>> SIMULATION INPUT: USER_HW_TOP_TB_DEF)
endif

ifdef OR_ONLY
$(warning >>> Only OpenRISC subsystem will be built)
GLOBAL_DEFINES+=OR_ONLY=1
endif

ifdef OFFSET_CONTROL
$(warning >>> MV Tracking Offset Setting ENABLED)
GLOBAL_DEFINES+=OFFSET_CONTROL=1
endif


ifdef SIM_EXT_MEM_SDRAM
$(warning >>> EXTERNAL MEMORY TYPE: SDRAM)
GLOBAL_DEFINES+=SIM_EXT_MEM_SDRAM=1
   ifdef SIM_SDRAMC2
   $(warning >>> SDRAMC_TRMODE: ON)
   GLOBAL_DEFINES+=SIM_SDRAMC2=1
      ifdef CAM_VGA
      else
         ifdef CAM_HD
         else
         $(error >>> SIM_SDRAMC2 supports only VGA and HD mode)
         endif
      endif
   endif
else
   ifdef SIM_SDRAMC2
   $(error >>> define SIM_EXT_MEM_SDRAM first!!)
   endif
$(warning >>> EXTERNAL MEMORY TYPE: SSRAM [DEFAULT])
endif

#ifdef VIM_READ_ZIGZAG_ORDER
#$(warning >>> VIM READ MODE: ORIGINAL ZIG-ZAG SCAN ORDER)
#GLOBAL_DEFINES+=VIM_READ_ZIGZAG_ORDER=1
#endif

#ifdef VIM_BURST_SUPPORT
#ifdef VIM_READ_ZIGZAG_ORDER
#$(error >>> You can NOT define VIM_READ_ZIGZAG_ORDER in VIM_BURST_SUPPORT mode)
#endif
#$(warning >>> VIM BURST READ ENABLED)
#GLOBAL_DEFINES+=VIM_BURST_SUPPORT=1
#endif

#ifdef ADF_BURST_SUPPORT
#$(warning >>> ADF BURST MODE ENABLED)
#GLOBAL_DEFINES+=ADF_BURST_SUPPORT=1
#endif

# H264E_WA_USE_CUSTOMIZED_HBURST
# A workaround to support burst lengths thoses are NOT supported in AMBA AHB
# ifdef H264E_WA_USE_CUSTOMIZED_HBURST
#$(warning >>> Use customized HBURST signals [WORKAROUND])
#GLOBAL_DEFINES+=H264E_WA_USE_CUSTOMIZED_HBURST=1
# endif
#GLOBAL_DEFINES+=VIM_BURST_SUPPORT=1
#GLOBAL_DEFINES+=CAM_BURST16_MODE=1
#GLOBAL_DEFINES+=ADF_BURST_SUPPORT=1

ifdef SLICE_MODE
$(warning >>> PB_UART used!!)
GLOBAL_DEFINES+=SLICE_MODE=1
endif

ifdef NO_DEBLOCK
GLOBAL_DEFINES+=NO_DEBLOCK=1
$(warning >>> DEBLOCKING FILTER DISABLED)
else
GLOBAL_DEFINES+=USE_ADF=1
$(warning >>> DEBLOCKING FILTER ENABLED)
endif

#ifdef USE_LT_OSC
#GLOBAL_DEFINES+=USE_LT_OSC=1
#$(warning >>> LT CLOCK DRIVEN BY LT OSC)
#else
#$(warning >>> LT CLOCK DRIVEN BY PB OSC)
#endif

#ifdef FLASH_BOOT
#GLOBAL_DEFINES+=FLASH_BOOT=1
#$(warning >>> FLASH BOOT ENABLED)
#else
#$(warning >>> FLASH BOOT DISABLED)
#endif

ifdef USE_DOUBLE_SDRAMC
GLOBAL_DEFINES+=USE_DOUBLE_SDRAMC=1
$(warning >>> both of two SDRAMC are enabled.)
endif

ifdef EXT_RAM_2_PORT
GLOBAL_DEFINES+=EXT_RAM_2_PORT=1
$(warning >>> External RAM is 2 port)
else
$(warning >>> External RAM is 1 port)
endif

# ifdef FPGA_TARGET
# GLOBAL_DEFINES+=FPGA_TARGET=1
# $(warning >>> FLASH BOOT ENABLED)
# endif

# ifdef MPW_TARGET
# GLOBAL_DEFINES+=MPW_TARGET=1
# $(warning >>> FLASH BOOT ENABLED)
# endif

ifdef ISP_ADD
GLOBAL_DEFINES+=ISP_ADD=1
$(warning >>> FLASH BOOT ENABLED)
endif

ifdef PB_REMOVE
GLOBAL_DEFINES+=PB_REMOVE=1
$(warning >>> PB-BOARD REMOVE ENABLED)
else
$(warning >>> PB-BOARD REMOVE DISABLED)
endif

ifdef USE_SDIO_FPGA_SIM
GLOBAL_DEFINES+=USE_SDIO_FPGA_SIM=1
$(warning >>> USE_SDIO_FPGA_SIMULATION ENABLED)
else
$(warning >>> USE_SDIO_FPGA_SIMULATION DISABLED)
endif

#ifdef PB_REMOVE
#ifndef FLASH_BOOT
#$(error >>> PB_REMOVE cannot be defined without using USE_LT_OSC and FLASH_BOOT mode!)
#endif
#ifndef USE_LT_OSC
#$(error >>> PB_REMOVE cannot be defined without using USE_LT_OSC and FLASH_BOOT mode!)
#endif
#endif

#ifdef CAM_BURST16_MODE
$(warning >>> CAM_IF transfers src frame with burst incr16)
GLOBAL_DEFINES+=CAM_BURST16_MODE=1
#else
#$(warning >>> CAM_IF transfers src frame with burst single)
#endif

ifdef SIM_USE_ISP
# GLOBAL_DEFINES+=SIM_USE_ISP=1
# $(warning >>> SIMULATION INPUT: ISP MODEL)
# else
# $(warning >>> SIMULATION INPUT: CAMERA MODEL [DEFAULT])
$(error >>> SIM_USE_ISP is not used any more. You have to use USE_ISP)
endif

ifdef USE_HIF
GLOBAL_DEFINES+=USE_HIF=1
$(warning >>> USE HIF)
else
$(warning >>> DO NOT USE HIF [DEFAULT])
endif

ifdef SIM_MEM2USB
GLOBAL_DEFINES+=SIM_MEM2USB=1
$(warning >>> USE HIF)
else
$(warning >>> DO NOT USE HIF [DEFAULT])
endif

ifdef PB_UART
GLOBAL_DEFINES+=PB_UART=1
$(warning >>> PB_UART HIF)
endif

ifdef ME_EARLY_TERMINATION
$(warning >>> PB_UART used!!)
GLOBAL_DEFINES+=ME_EARLY_TERMINATION=1
endif

ifdef SPEED_CONTROL
$(warning >>> PB_UART used!!)
GLOBAL_DEFINES+=SPEED_CONTROL=1
endif

ifdef SIMULATION_FIRMWARE
$(warning >>> SIMULATION_FIRMWARE compile used!!)
GLOBAL_DEFINES+=SIMULATION_FIRMWARE=1
endif

ifdef TM_PLL
$(warning >>> TEST_MODE for PLL is running!!)
GLOBAL_DEFINES+=TM_PLL=1
endif

ifdef TM_NANDTREE0
$(warning >>> TEST_MODE for NANDtree0 is running!!)
GLOBAL_DEFINES+=TM_NANDtree0=1
endif

ifdef TM_NANDTREE1
$(warning >>> TEST_MODE for NANDtree1 is running!!)
GLOBAL_DEFINES+=TM_NANDtree1=1
endif

ifdef TM_USBPHY
$(warning >>> TEST_MODE for USB_PHY is running!!)
GLOBAL_DEFINES+=TM_USBPHY=1
endif

ifdef RES32_MODE
$(warning >>> jpeg res32_mode is enable!!)
GLOBAL_DEFINES+=RES32_MODE=1
endif

ifdef I2C_SLAVE_ON
$(warning >>> I2C Master can write/read I2C_SLAVE_model!!)
GLOBAL_DEFINES+=I2C_SLAVE_ON=1
endif

ifdef DIAGNOSIS_TEST
$(warning >>> diagnosis test!!)
GLOBAL_DEFINES+=DIAGNOSIS_TEST=1
endif

ifdef SDF_ANNOTATE
$(warning >>> sdf file annotation is enable!!)
GLOBAL_DEFINES+=SDF_ANNOTATE=1
endif

ifdef ISP_HW_REMOVE
$(warning >>> Remove ISP hardware for 4200 which is shrinked version of 4100.)
GLOBAL_DEFINES+=ISP_HW_REMOVE=1
endif
###################################################
#FPGA TEST kik
###################################################
ifdef FPGA_SW_TEST
$(warning >>> DOWNLOAD PROGRAM FROM PC TO FPGA.)
GLOBAL_DEFINES+=FPGA_SW_TEST=1
endif
 
ifdef FPGA_SDRAM_TEST
$(warning >>> SET FPGA_SDRAM_TEST.....)
GLOBAL_DEFINES+=FPGA_SDRAM_TEST=1
endif
###################################################

ifdef GATE_SIM
$(warning >>> Gate sim mode is enable.)
GLOBAL_DEFINES+=GATE_SIM=1
endif
# }}}


# #################################################
# Set global environment variable (TOP_MODULE, TB_MODULE, path etc)
# #################################################
# {{{
ifeq ($(findstring FPGA_TARGET,$(GLOBAL_DEFINES)),FPGA_TARGET)
TOP_MODULE=vidan4100_fpga_top
TB_MODULE =$(TOP_MODULE)_tb
endif

ifeq ($(findstring MPW_TARGET,$(GLOBAL_DEFINES)),MPW_TARGET)
TOP_MODULE=vidan4100
TB_MODULE =vidan4100_top_tb
endif

HARDWARE_DIR= $(TOP_DIR)/hardware
LIBRARY_DIR=$(TOP_DIR)/library
VERIFICATION_DIR=$(TOP_DIR)/verification
SOFTWARE_DIR=$(TOP_DIR)/software
DCOMPILER_DIR=$(TOP_DIR)/synthesis
# SIM_DIR=$(TOP_DIR)/verification/sim
# WORK_DIR=$(SIM_DIR)/work
# INPUT_DATA_DIR=$(SIM_DIR)/input_data

FPGA_DIR=$(TOP_DIR)/fpga
FPGA_SYN_DIR=$(FPGA_DIR)/synplify
FPGA_PNR_DIR=$(FPGA_DIR)/xilinx

# Synthesis: Synplicity Synplify Pro
SYNPLIFY_PRO=synplify_pro
FPGA_SYN_PROJECT_TEMPLATE=$(FPGA_SYN_DIR)/syn.prj.template
FPGA_SYN_DST_DIR=$(FPGA_SYN_DIR)/netlist
FPGA_SYN_PROJECT=$(FPGA_SYN_DST_DIR)/syn.prj

# ======= RTL Include path ======= #
INC_RTL_PATH= \
   $(HARDWARE_DIR)/system/ahb_interconnect/hdl \
	$(HARDWARE_DIR)/system/ahb_lite/hdl \
	$(HARDWARE_DIR)/accelerator/h264e/hdl/h264_core/msg \
	$(HARDWARE_DIR)/interface/ahb_wrapped_or_uart/hdl/uart16550 \
	$(HARDWARE_DIR)/interface/ahb_wrapped_sdramc/hdl \
   $(HARDWARE_DIR)/interface/spi_master/hdl/ \
   $(HARDWARE_DIR)/interface/pci/hdl/ \
   $(HARDWARE_DIR)/peripheral/hif/hdl/ \
   $(HARDWARE_DIR)/interface/i2c_master/hdl/ \
   $(HARDWARE_DIR)/interface/gpio/hdl/
ifeq ($(findstring OR1200,$(GLOBAL_DEFINES)),OR1200)
INC_RTL_PATH+= \
	$(HARDWARE_DIR)/system/or1200/hdl
endif
ifeq ($(findstring FPGA_TARGET,$(GLOBAL_DEFINES)),FPGA_TARGET)
INC_RTL_PATH+= \
        $(HARDWARE_DIR)/system/ba22/hdl/ \
        $(HARDWARE_DIR)/system/debug_if/hdl/ \
        $(HARDWARE_DIR)/system/tap/hdl \
        $(HARDWARE_DIR)/interface/usb_dev/hdl/
else
ifeq ($(findstring BA22,$(GLOBAL_DEFINES)),BA22)
INC_RTL_PATH+= \
        $(HARDWARE_DIR)/system/ba22/hdl/ \
        $(HARDWARE_DIR)/system/debug_if/hdl/ \
        $(HARDWARE_DIR)/system/tap/hdl
endif
endif
ifneq ($(findstring FPGA_TARGET,$(GLOBAL_DEFINES)),FPGA_TARGET)
INC_RTL_PATH+= \
   $(HARDWARE_DIR)/interface/usb_dev/hdl/
endif

INC_VERI_PATH= \
   $(VERIFICATION_DIR)/hardware/isp_sensor_model/hdl/
ifeq ($(findstring FPGA_TARGET,$(GLOBAL_DEFINES)),FPGA_TARGET)
INC_FPGA_PATH= \
   $(FPGA_DIR)/hardware/design/hdl/
endif

# ======= RTL source directory ======= #
HARDWARE_RTL_DIR= \
   $(HARDWARE_DIR)/accelerator/h264e/hdl/ \
   $(HARDWARE_DIR)/accelerator/isp/hdl/ \
   $(HARDWARE_DIR)/accelerator/jpeg/hdl/ \
   $(HARDWARE_DIR)/interface/ahb_wrapped_or_uart/hdl/ \
   $(HARDWARE_DIR)/interface/flash_interface/hdl/ \
   $(HARDWARE_DIR)/interface/usb_source_sel/hdl/ \
   $(HARDWARE_DIR)/interface/camera_interface/hdl/ \
   $(HARDWARE_DIR)/interface/sdio/hdl/ \
   $(HARDWARE_DIR)/interface/pci/hdl/ \
   $(HARDWARE_DIR)/interface/usb/hdl/ \
   $(HARDWARE_DIR)/interface/vim_to_ahb/hdl/ \
   $(HARDWARE_DIR)/interface/sccb/hdl/ \
   $(HARDWARE_DIR)/interface/l1_spi_slave/hdl/ \
   $(HARDWARE_DIR)/interface/i2s/hdl/ \
   $(HARDWARE_DIR)/interface/i2c_master/hdl/ \
   $(HARDWARE_DIR)/interface/spi_master/hdl/ \
   $(HARDWARE_DIR)/interface/gpio/hdl/ \
   $(HARDWARE_DIR)/interface/dvp/hdl/ \
   $(HARDWARE_DIR)/interface/ahb_wrapped_sdramc/hdl/ \
   $(HARDWARE_DIR)/peripheral/ahb_regs/hdl/ \
   $(HARDWARE_DIR)/peripheral/arm_presented/hdl/ \
   $(HARDWARE_DIR)/peripheral/stream_receiver_sel/hdl/ \
   $(HARDWARE_DIR)/peripheral/stream_word_to_mem/hdl/ \
   $(HARDWARE_DIR)/peripheral/hif/hdl/ \
   $(HARDWARE_DIR)/peripheral/spi_slave_buf/hdl/ \
   $(HARDWARE_DIR)/peripheral/spi_ip_bus/hdl/ \
   $(HARDWARE_DIR)/system/wishbone_to_ahb/hdl/ \
   $(HARDWARE_DIR)/system/ahb_interconnect/hdl/ \
   $(HARDWARE_DIR)/system/ahb_lite_sync_bridge/hdl/ \
   $(HARDWARE_DIR)/system/risc_wishbone_wrapper/hdl/ \
   $(HARDWARE_DIR)/system/or32_vec_rom/hdl/ \
   $(HARDWARE_DIR)/system/code_rom/hdl/ \
   $(HARDWARE_DIR)/system/data_ram/hdl/ \
   $(HARDWARE_DIR)/system/open_risc_cntl/hdl/ \
   $(HARDWARE_DIR)/system/ahb_agent/hdl/ \
   $(HARDWARE_DIR)/system/ahb_fsb/hdl/ \
   $(HARDWARE_DIR)/system/ahb_lite/hdl/ \
   $(HARDWARE_DIR)/system/apb/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/cam_if/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/i2s/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/code_rom/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/pci/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/data_ram/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/dvp/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/h264e_memory_wrap/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/spi/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/isp/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/jpeg/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/sdio/hdl/ \
   $(HARDWARE_DIR)/memory_wrap/sdramc/hdl/ \
   $(HARDWARE_DIR)/top/hdl/
ifeq ($(findstring OR1200,$(GLOBAL_DEFINES)),OR1200)
HARDWARE_RTL_DIR+= \
   $(HARDWARE_DIR)/memory_wrap/openrisc/hdl/ \
   $(HARDWARE_DIR)/system/or1200/hdl/
endif
ifeq ($(findstring BA22,$(GLOBAL_DEFINES)),BA22)
HARDWARE_RTL_DIR+= \
   $(HARDWARE_DIR)/memory_wrap/ba22/hdl/ \
   $(HARDWARE_DIR)/system/ba22/hdl/ \
   $(HARDWARE_DIR)/system/debug_if/hdl/ \
   $(HARDWARE_DIR)/system/tap/hdl/
endif
ifneq ($(findstring FPGA_TARGET,$(GLOBAL_DEFINES)),FPGA_TARGET)
HARDWARE_RTL_DIR+= \
   $(HARDWARE_DIR)/interface/usb_dev/hdl/ \
   $(HARDWARE_DIR)/interface/usb_phy/hdl/ \
   $(HARDWARE_DIR)/system/cpm/hdl/
endif
ifeq ($(findstring FPGA_TARGET,$(GLOBAL_DEFINES)),FPGA_TARGET)
HARDWARE_RTL_DIR+= \
   $(HARDWARE_DIR)/interface/usb_dev/hdl/
endif


VERIFICATION_RTL_DIR= \
   $(VERIFICATION_DIR)/hardware/ahb_tracer/hdl/ \
   $(VERIFICATION_DIR)/hardware/isp_sensor_model/hdl/ \
   $(VERIFICATION_DIR)/hardware/ahb_test_ip/hdl/ \
   $(VERIFICATION_DIR)/hardware/transaction_recorder/hdl/ \
   $(VERIFICATION_DIR)/hardware/boot_flash_model/hdl/ \
   $(VERIFICATION_DIR)/hardware/usb_slave/hdl/ \
   $(VERIFICATION_DIR)/hardware/ovt_sensor_model/hdl/ \
   $(VERIFICATION_DIR)/hardware/tube/hdl/ \
   $(VERIFICATION_DIR)/hardware/sram_model/hdl/ \
   $(VERIFICATION_DIR)/hardware/sdram_model/hdl/ \
   $(VERIFICATION_DIR)/hardware/l1_spi_master/hdl/ \
   $(VERIFICATION_DIR)/hardware/dvp_recoder/hdl/ \
   $(VERIFICATION_DIR)/hardware/i2c_master_model/hdl/ \
   $(VERIFICATION_DIR)/hardware/sdio_recoder/hdl/ \
   $(VERIFICATION_DIR)/hardware/spi_flash_model/hdl/ \
   $(VERIFICATION_DIR)/hardware/i2c_slave_model/hdl/ \
   $(VERIFICATION_DIR)/hardware/i2s_master_model/hdl/ 		#090412_hunnoh_i2s_master_model+
ifeq ($(findstring MPW_TARGET,$(GLOBAL_DEFINES)),MPW_TARGET)
VERIFICATION_RTL_DIR+= \
   $(VERIFICATION_DIR)/hardware/top_tb/hdl/
endif

ifeq ($(findstring FPGA_TARGET,$(GLOBAL_DEFINES)),FPGA_TARGET)
LIBRARY_RTL_DIR= \
   $(LIBRARY_DIR)/memory_model \
   $(LIBRARY_DIR)/xilinx \
   $(LIBRARY_DIR)/gtech_for_FPGA/src_ver/
else
LIBRARY_RTL_DIR= \
	$(LIBRARY_DIR)/silttera/IO/sl13ugfsio45b25a02/verilog/ \
	$(LIBRARY_DIR)/silttera/IO/sl13ugfsio45b33a03/verilog/ \
	$(LIBRARY_DIR)/silttera/Logic/sl13ugfsdsca03/verilog/ \
	$(LIBRARY_DIR)/silttera/pll/US13250/verilog/ \
	$(LIBRARY_DIR)/silttera/usb_phy/verilog/ \
	$(LIBRARY_DIR)/gtech/src_ver/

#	$(LIBRARY_DIR)/silttera/pll/US18220/verilog/
endif

ifeq ($(findstring MPW_TARGET,$(GLOBAL_DEFINES)),MPW_TARGET)
LIBRARY_RTL_DIR+= \
   $(LIBRARY_DIR)/memory_model \
   $(LIBRARY_DIR)/silttera/memory/ROM/JPEG_AC_ROM0/Typical/JPEG_AC_ROM0_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/ROM/DATA_ROM/Typical/DATA_ROM_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM0/Typical/CODE_ROM0_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM1/Typical/CODE_ROM1_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM2/Typical/CODE_ROM2_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM3/Typical/CODE_ROM3_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM4/Typical/CODE_ROM4_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM5/Typical/CODE_ROM5_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/ROM/JPEG_AC_ROM1/Typical/JPEG_AC_ROM1_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_1024_12/Typical/DPRAM_1024_12_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_1024_32/Typical/DPRAM_1024_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_128_32/Typical/DPRAM_128_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_128_40/Typical/DPRAM_128_40_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_256_32/Typical/DPRAM_256_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_64_32/Typical/DPRAM_64_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_16_32/Typical/DPRAM_16_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_512_32/Typical/DPRAM_512_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_4096_32/Typical/DPRAM_4096_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_1024_10/Typical/DPRAM_1024_10_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_64_32/Typical/u_SRAM_64_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_64_64/Typical/u_SRAM_64_64_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_128_8/Typical/u_SRAM_128_8_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_16_8/Typical/u_SRAM_16_8_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_512_64/Typical/u_SRAM_512_64_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_128_12/Typical/u_SRAM_128_12_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_1280_30/Typical/u_SRAM_1280_30_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_1024_64/Typical/u_SRAM_1024_64_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_16384_32/Typical/u_SRAM_16384_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_16K_32/Typical/u_SRAM_16K_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_1280_8/Typical/u_SRAM_1280_8_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_32_32/Typical/u_SRAM_32_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_128_32/Typical/u_SRAM_128_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_49_120/Typical/u_SRAM_49_120_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_64_16/Typical/u_SRAM_64_16_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_256_64/Typical/u_SRAM_256_64_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_256_32/Typical/u_SRAM_256_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_8192_32/Typical/u_SRAM_8192_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_4096_32/Typical/u_SRAM_4096_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_1024_32/Typical/u_SRAM_1024_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_1280_10/Typical/u_SRAM_1280_10_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_512_32/Typical/u_SRAM_512_32_rtl.v \
   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_64_22/Typical/u_SRAM_64_22_rtl.v
#   $(LIBRARY_DIR)/silttera/memory/ROM/JPEG_AC_ROM0/Worst/JPEG_AC_ROM0.v \
#   $(LIBRARY_DIR)/silttera/memory/ROM/DATA_ROM/Worst/DATA_ROM.v \
#   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM0/Worst/CODE_ROM0.v \
#   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM1/Worst/CODE_ROM1.v \
#   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM2/Worst/CODE_ROM2.v \
#   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM3/Worst/CODE_ROM3.v \
#   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM4/Worst/CODE_ROM4.v \
#   $(LIBRARY_DIR)/silttera/memory/ROM/CODE_ROM5/Worst/CODE_ROM5.v \
#   $(LIBRARY_DIR)/silttera/memory/ROM/JPEG_AC_ROM1/Worst/JPEG_AC_ROM1.v \
#   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_1024_12/Worst/DPRAM_1024_12.v \
#   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_1024_32/Worst/DPRAM_1024_32.v \
#   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_128_32/Worst/DPRAM_128_32.v \
#   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_128_40/Worst/DPRAM_128_40.v \
#   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_256_32/Worst/DPRAM_256_32.v \
#   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_64_32/Worst/DPRAM_64_32.v \
#   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_16_32/Worst/DPRAM_16_32.v \
#   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_512_32/Worst/DPRAM_512_32.v \
#   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_4096_32/Worst/DPRAM_4096_32.v \
#   $(LIBRARY_DIR)/silttera/memory/DPRAM/DPRAM_1024_10/Worst/DPRAM_1024_10.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_64_32/Worst/u_SRAM_64_32.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_64_64/Worst/u_SRAM_64_64.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_128_8/Worst/u_SRAM_128_8.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_16_8/Worst/u_SRAM_16_8.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_512_64/Worst/u_SRAM_512_64.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_128_12/Worst/u_SRAM_128_12.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_1280_30/Worst/u_SRAM_1280_30.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_1024_64/Worst/u_SRAM_1024_64.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_16384_32/Worst/u_SRAM_16384_32.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_16K_32/Worst/u_SRAM_16K_32.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_1280_8/Worst/u_SRAM_1280_8.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_32_32/Worst/u_SRAM_32_32.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_128_32/Worst/u_SRAM_128_32.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_49_120/Worst/u_SRAM_49_120.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_64_16/Worst/u_SRAM_64_16.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_256_64/Worst/u_SRAM_256_64.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_256_32/Worst/u_SRAM_256_32.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_8192_32/Worst/u_SRAM_8192_32.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_4096_32/Worst/u_SRAM_4096_32.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_1024_32/Worst/u_SRAM_1024_32.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_1280_10/Worst/u_SRAM_1280_10.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_512_32/Worst/u_SRAM_512_32.v \
#   $(LIBRARY_DIR)/silttera/memory/SPRAM/u_SRAM_64_22/Worst/u_SRAM_64_22.v
endif

#ifeq ($(findstring FPGA_TARGET,$(GLOBAL_DEFINES)),FPGA_TARGET)
#FPGA_RTL_DIR= \
#   $(FPGA_DIR)/hardware/ahb_reg_forFPGA/hdl/ \
#   $(FPGA_DIR)/hardware/top/hdl/ \
#   $(FPGA_DIR)/hardware/top_tb/hdl/
#endif
###############
# FPGA kik
###############
ifeq ($(findstring FPGA_TARGET,$(GLOBAL_DEFINES)),FPGA_TARGET)
 ifeq ($(findstring FPGA_SDRAM_TEST,$(GLOBAL_DEFINES)),FPGA_SDRAM_TEST)
 FPGA_RTL_DIR= \
   $(FPGA_DIR)/hardware/ahb_reg_forFPGA/hdl/ \
   $(FPGA_DIR)/hardware/top_sdram/hdl/ \
   $(FPGA_DIR)/hardware/top_tb_sdram/hdl/
 else
 FPGA_RTL_DIR= \
   $(FPGA_DIR)/hardware/ahb_reg_forFPGA/hdl/ \
   $(FPGA_DIR)/hardware/top/hdl/ \
   $(FPGA_DIR)/hardware/top_tb/hdl/
 endif
endif
###############

INC_PATH= \
	$(INC_RTL_PATH) \
	$(INC_VERI_PATH) \
   $(INC_FPGA_PATH)

ENV_RTL_DIR= \
	$(VERIFICATION_RTL_DIR) \
	$(LIBRARY_RTL_DIR) \
	$(FPGA_RTL_DIR)

POST_RTL_DIR= \
   $(HARDWARE_DIR)/interface/l1_spi_slave/hdl/ \
	$(ENV_RTL_DIR)

RTL_DIR= \
	$(HARDWARE_RTL_DIR) \
	$(ENV_RTL_DIR)

# ======= Software source directory ======= #
SOFTWARE_SRC_DIR= $(SOFTWARE_DIR)/or
# }}}

# #################################################
# ignore the following file names and path names
# #################################################
# {{{
EXC_SRC_LIST=*_p.v *_h.v msg.v .*
ifeq ($(findstring FPGA_TARGET,$(GLOBAL_DEFINES)),FPGA_TARGET)
EXC_SRC_LIST+=*spare_gates_for_fib.*
EXC_SRC_LIST+=*premitive.v
endif

EXC_PATH_LIST=*.org* *.bak*
EXC_PATH_LIST+= *xilinx/core_x4*

EXC_SRCS=$(addprefix ! -name ,$(addsuffix ",$(addprefix ",$(EXC_SRC_LIST))))
EXC_PATHS=$(addprefix ! -path ,$(addsuffix ",$(addprefix ",$(EXC_PATH_LIST))))
EXCS=$(EXC_SRCS) $(EXC_PATHS)
# }}}


# Firmware

#-include ../../user.mk
DEP=../..
include $(DEP)/def.mk

# Tool-chain configuration
#COMPILER_PATH=/home/jykim/lgdtv_software/opt/ba-elf
#COMPILER_PATH=/home/vidan4110/vidan4110_test/download/opt/ba-elf
#COMPILER_PATH=/home/ksw/vidan_usb_driver/download/opt/ba-elf
COMPILER_PATH=../../../download/opt/ba-elf
#COMPILER_PATH=/tmp/opt/ba-elf
CROSS_COMPILE=$(COMPILER_PATH)/bin/ba-elf-

AS=$(CROSS_COMPILE)gcc
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
DUMP=$(CROSS_COMPILE)objdump
COPY=$(CROSS_COMPILE)objcopy

HEX_CONV=./bin/bin2hex --width 1
ENDIAN_CONV=./bin/swapendian
MEMFILE=./bin/memfile
CRC32EXE=./bin/crc32

BIN2TXT=./bin/bin2txt.pl

# =================================================
# FIXME
# =================================================
# OBJ_DIR=./obj
SIM_DIR=../../verification/sim
COE_DIR=../../library/xilinx/core_x5
SPI_MASTER_DATA=../../verification/sim/l1_spi_master_data

# Target
SW_TARGET=vidan4100

#ASM_DIR=common
#SRCS=common

ASMS= \
     $(wildcard common/*.S) \
     ucos/divsi3.S \
     ucos/interrupt.S \
     ucos/memset.S \
     ucos/or1200s.S 

SRCS= \
   $(wildcard common/*.c) \
   $(wildcard interface/*.c) \
   $(wildcard jpeg/*.c) \
   $(wildcard src/*.c)

INTERNALSRCS= \
   $(wildcard internal/*.c) \
   $(wildcard ucos/*.c)

OBJS=$(SRCS:.c=.o) $(ASMS:.S=.o) $(INTERNALASMS:.S=.o) 
INC_PATH=-Iinterface -Isrc -Icommon -Iucos -Ijpeg

# =================================================
# Compilation options
# =================================================
LIB_PATH=-L$(COMPILER_PATH)/ba-elf/lib/ba2 -L$(COMPILER_PATH)/lib/gcc/ba-elf/4.2.1/ba2
SECTION_PATH=or32_ba22.ld
CFLAGS=-Wall -g -march=ba2  $(INC_PATH) -O1 $(foreach p,$(GLOBAL_DEFINES),-D$p)
ASMFLAGS=$(CFLAGS)

LDFLAGS=$(LIB_PATH) -T$(SECTION_PATH) -Map $(SW_TARGET).map -lm
DUMPFLAGS=-D -EB -l --source

INTERNALASMS=$(INTERNALSRCS:.c=.S) 

all: .depend $(SW_TARGET).dump $(SW_TARGET).little.bin $(SW_TARGET).rom2ram.little.bin $(SW_TARGET).internal.little.bin CRC_GEN CPBIN

#make your own cpbin file for aadrvark uploading
include cpbin

%.o: %.S
	@echo "Compile $< ..."
	@$(AS) $(ASMFLAGS) -c -o $@ $<

%.o: %.c
	@echo "Compile $< ..."
	@$(CC) $(CFLAGS) -c -o $@ $<

%.S: %.c
	@echo "Compile $< ..."
	@$(CC) $(CFLAGS) -S -o internal/temp.S $<
	@sed s/".section .text"/".section .internalrom, \"ax\""/ < internal/temp.S > $@
	@rm internal/temp.S

$(SW_TARGET): $(INTERNALASMS) $(OBJS)
	@echo "Link $< to $@"
	@$(LD) -o $@ $(OBJS) $(LDFLAGS)

$(SW_TARGET).bin: $(SW_TARGET)
	@$(COPY) -R .stack -R .bss -R .vectors -R .internalrom -R .shbss -R .talias -R .stab -R .stabstr \
				-R .data -R .end_mark \
          	-O binary --gap-fill 0 $< $@

$(SW_TARGET).rom2ram.bin: $(SW_TARGET)
	@$(COPY) -R .stack -R .bss -R .vectors -R .internalrom -R .shbss -R .talias -R .stab -R .stabstr \
				-R .vectors2 -R .text -R .rodata -R .rodata.cst4 -R .rodata.str1.1 \
          	-O binary --gap-fill 0 $< $@

$(SW_TARGET).internal.bin: $(SW_TARGET)
	@$(COPY) -R .stack -R .bss -R .vectors -R .shbss -R .talias -R .stab -R .stabstr \
				-R .data -R .end_mark \
				-R .vectors2 -R .text -R .rodata -R .rodata.cst4 -R .rodata.str1.1 \
          	-O binary --gap-fill 0 $< $@

$(SW_TARGET).dump: $(SW_TARGET)
	@$(DUMP) $(DUMPFLAGS) $(SW_TARGET) > $(SW_TARGET).dump

$(SW_TARGET).little.bin: $(SW_TARGET).little.hex
	@$(BIN2TXT) -r $< $@

$(SW_TARGET).little.hex: $(SW_TARGET).bin
	@$(BIN2TXT) -l $< $@

$(SIM_DIR)/smem65536x32.mif: $(SW_TARGET).little.bin
	@$(BIN2TXT) -x 2 $< $@
	@cp $@ .

#$(SW_TARGET).hex: $(SW_TARGET).bin
#	@$(HEX_CONV) $(SW_TARGET).bin > $(SW_TARGET).hex

CRC_GEN: CRC32EXE_MAKE
	@echo "Attach crc32."
	@$(CRC32EXE) $(SW_TARGET).rom2ram.little.bin $(SW_TARGET).little.bin

CRC32EXE_MAKE: $(CRC32EXE).c
	@gcc $< -o $(CRC32EXE)

$(SW_TARGET).rom2ram.little.bin: $(SW_TARGET).rom2ram.little.hex
	@$(BIN2TXT) -r $< $@

$(SW_TARGET).rom2ram.little.hex: $(SW_TARGET).rom2ram.bin
	@$(BIN2TXT) -l $< $@

$(SW_TARGET).internal.little.bin: $(SW_TARGET).internal.little.hex
	@$(BIN2TXT) -r $< $@

$(SW_TARGET).internal.little.hex: $(SW_TARGET).internal.bin
	@$(BIN2TXT) -l $< $@


cscope:
	find . \( -name '*.c' -o -name '*.h' -o -name '*.S' \) -print > cscope.files
	cscope -i cscope.files

.depend:
	@makedepend -f- -- $(CFLAGS) -- $(SRCS) > .depend
#	gccmakedep -f- -- $(CFLAGS) -- $(SRCS) > .depend

clean:
	rm -f $(SW_TARGET) $(OBJS) $(INTERNALASMS) $(SW_TARGET).* *.bak .*.bak .depend $(CRC32EXE)

# $(OBJ_DIR):
# 	@mkdir $(OBJ_DIR)

copy: $(SW_TARGET).little.bin
	@if [ -n "$(FIRMWARE_INSTALL_PATH)" ]; then \
		echo "Copy $(SW_TARGET).little.bin to $(FIRMWARE_INSTALL_PATH)..."; \
		scp $(SW_TARGET).little.bin $(FIRMWARE_INSTALL_PATH); \
	fi

-include .depend

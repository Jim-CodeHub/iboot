#Base config
CROSS_COMPILE = arm-linux-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
TOP_DIR  = $(PWD)
SUB_DIRS = arch driver common lib Soc board

#Refer config
CC_REFER = -c -I $(TOP_DIR)/include
#LD_REFER = -Ttext 0x40000000   #uboot环境裸板开发使用0x40000000
LD_REFER = -Ttext 0x02023400  #mboot环境只能用iRAM，0x02023400 
COPY_REFER = -O binary
DUMP_REFER = -D

#OBJ config
OBJ = $(TOP_DIR)/arch/start.o 
OBJ += $(TOP_DIR)/Soc/clock.o 
OBJ += $(TOP_DIR)/common/main.o 
OBJ += $(TOP_DIR)/driver/led.o
OBJ += $(TOP_DIR)/driver/uart.o
OBJ += $(TOP_DIR)/lib/lib.o
OBJ += $(TOP_DIR)/board/RAM/dmc_r0.o
OBJ += $(TOP_DIR)/board/RAM/dmc_r1.o
OBJ += $(TOP_DIR)/board/RAM/dmc_r2.o
TAG = start 

#LIB config
LIB = $(TOP_DIR)/lib/libgcc.a $(TOP_DIR)/lib/libc.a

export CC LD LIB OBJ OBJCOPY OBJDUMP CC_REFER LD_REFER COPY_REFER DUMP_REFER


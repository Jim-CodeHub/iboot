#!/bin/bash

if [ $# != 1 ]
then
    echo "Usage: ./sd_fuse.sh </dev/xxx>"
    exit 0
fi

if [ ! -b $1 ]
then
    echo "The device isn't block file"
    exit 0
fi

BASENAME=`basename $1`
FILESIZE=`cat /sys/block/${BASENAME}/size`

if [ $FILESIZE -le 0 ] 
then
    echo "The block device is invalid"
    exit 0
fi

BOOT=../../boot.bin
MKBL2=../mkbl2

if [ ! -f ${BOOT} ] 
then
    echo "boot.bin isn't exist"
    exit 0
fi

if [ ! -f ${MKBL2} ]
then
    echo "mkbl2 isn't exist"
    exit 0
fi

${MKBL2} ${BOOT} bl2.bin 14336

#注：块设备分区，一个block大小是512Byte，根据三星官方手册分配空间
bl1_position=1      #BL1偏移1*512=512Byte  BL1使用空间16*512=8kb
bl2_position=17     #BL2偏移8kb BL2使用空间32*512=16kb
boot_position=49    #boot偏移16kb boot使用空间656*512=328kb
tzsw_position=705   #tzsw偏移328kb 使用空间不限制
#以上为SD卡烧录的偏移分区情况，对eMMC烧录不需要第一个512B的偏移，其它相同

echo "================================="
echo "BL1 FUSING"
dd iflag=dsync oflag=dsync if=./bl1.bin of=$1 seek=$bl1_position

echo "================================="
echo "BL2 FUSING"
dd iflag=dsync oflag=dsync if=./bl2.bin of=$1 seek=$bl2_position

echo "================================="
echo "BOOT FUSING"
dd iflag=dsync oflag=dsync if=${BOOT} of=$1 seek=$boot_position

echo "================================="
echo "TZSW FUSING"
#安全区不是必选，不烧录也能运行
dd iflag=dsync oflag=dsync if=./tzsw.bin of=$1 seek=$tzsw_position

echo "Fusing complete!"


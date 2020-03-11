include ./config.mk

#链接成目标文件->剥离头部信息->生成反汇编供查看(非必要)
all:$(SUB_DIRS)
	$(LD) $(LD_REFER) $(OBJ) $(LIB) -o $(TAG) 
	$(OBJCOPY) $(COPY_REFER) $(TAG) boot.bin
	$(OBJDUMP) $(DUMP_REFER) $(TAG) > boot.dis

$(SUB_DIRS):ECHO
	@make -C $@	

ECHO:

clean:
	@rm -rf $(shell find ./ -name "*.o")
	@rm -rf $(TAG) boot.bin boot.dis sd_fuse/fusing/bl2.bin

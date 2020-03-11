/*
 *函数功能：1 - 判断文件大小，截短并读取文件
 *          2 - 累计文件内容总和，并新建文件
 *概括分析：截短uboot.bin文件，追加checksum，新建文件bl2.bin(截短uboot.bin-新建bl2.bin)
 *原理分析：
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_JUGE1(RET, VAL, MSG, HAN) do{if(RET != VAL){puts(MSG); HAN;}}while(0)
#define ERROR_JUGE2(RET, VAL, MSG, HAN) do{if(RET == VAL){puts(MSG); HAN;}}while(0)

int main(int argc, char *argv[])
{
    FILE *fp;
    int buff_size, file_size, read_byte;
    unsigned int i, checksum = 0;
    char *buff = NULL;

    ERROR_JUGE1(argc, 4, "Usage:./mkbl2 <uboot.bin> <bl2.bin> <size>", return -1);

    buff_size = atoi(argv[3]);
    buff = calloc(1, buff_size);
    ERROR_JUGE2(buff, NULL, "calloc failed", return -1);

    /*1 - start*/
    fp = fopen(argv[1], "rb");
    ERROR_JUGE2(fp, NULL, "open failed", free(buff);return -1);

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp); 
    fseek(fp, 0, SEEK_SET);
    
    if(buff_size > file_size)   
    {
        puts("unsupported size"); 
        free(buff);
        fclose(fp);
        return -1;
    }

    read_byte = fread(buff, 1, buff_size, fp);  //截短uboot.bin
    ERROR_JUGE1(read_byte, buff_size, "read failed", return -1);

    fclose(fp);
    /*1 - end  */

    /*2 - start*/
    for(i = 0; i < (1024 * 14) - 4; i++)
    {
        checksum += (unsigned char)buff[i]; 
    }
    *(unsigned int *)(buff + i) = checksum; //buff为char类型占用一个字节，checksum值很大，必须已unsigned int类型存储，故必须强转
    
    fp = fopen(argv[2], "wb");
    ERROR_JUGE2(fp, NULL, "open failed", free(buff);return -1);

    read_byte = fwrite(buff, 1, buff_size, fp);
    ERROR_JUGE1(read_byte, buff_size, "write failed", return -1);

    free(buff);
    fclose(fp);
    /*2 - end  */

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_JUGE1(RET, VAL, MSG, HAN) do{if(RET != VAL){puts(MSG); HAN;}}while(0)
#define ERROR_JUGE2(RET, VAL, MSG, HAN) do{if(RET == VAL){puts(MSG); HAN;}}while(0)

int main(int argc, char *argv[])
{
    FILE *fp;
    int buff_size, file_size;
    unsigned int i, checksum = 0;
    char *buff = NULL;

    ERROR_JUGE1(argc, 4, "Usage:./mkbl2 <uboot.bin> <bl2.bin> <size>", return -1);

    buff_size = atoi(argv[3]);
    buff = calloc(1, buff_size);
    ERROR_JUGE2(buff, NULL, "calloc failed", return -1);

    /*1 - start*/
    fp = fopen(argv[1], "rb");
    ERROR_JUGE2(fp, NULL, "open failed", free(buff);return -1);

    fread(buff, 1, buff_size, fp);

    fclose(fp);
    /*1 - end  */

    /*2 - start*/
    for(i = 0; i < (1024 * 14) - 4; i++)
    {
        checksum += (unsigned char)buff[i]; 
    }
    *(unsigned int *)(buff + i) = checksum; 
    
    fp = fopen(argv[2], "wb");
    ERROR_JUGE2(fp, NULL, "open failed", free(buff);return -1);

    fwrite(buff, 1, buff_size, fp);

    free(buff);
    fclose(fp);
    /*2 - end  */

    return 0;
}

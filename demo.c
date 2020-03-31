// Sample demo for QuickLZ 1.5.x

// Remember to define QLZ_COMPRESSION_LEVEL and QLZ_STREAMING_MODE to the same values for the compressor and decompressor

#include <stdio.h>
#include <stdlib.h>

#include "quicklz.h"

int main(int argc, char* argv[])
{

    unsigned short in_buf[] = {3026, 3026, 3026, 4552, 522, 1657, 522, 522, 522, 1657, 522, 522, 522, 522, 522, 1657, 522,\
                                1657, 522, 522, 522, 1657, 522, 522, 522, 1657, 522, 522, 522, 522, 522, 522, 522, 1657, \
                                522, 522, 522, 1657, 522, 1657, 522, 1657, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                1657, 522, 522, 522, 1657, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 1657, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                1657, 522, 522, 522, 1657, 522, 1657, 522, 1657, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 522, 1657, 522, 522, 522, 1657, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 1657, 522, 522, 522, 522, 522, 1657, 522, 522, 522, 1657, 522, 1657, 522, 522, \
                                522, 1657, 522, 522, 522, 1657, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 1657, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, 522, \
                                522, 522, 522, 1657, 522, 522, 522, 1657, 522, 1657, 522, 522, 522, 1657, 522, 1657, 522, 1657, 522, 1000};

    qlz_state_compress *state_compress = (qlz_state_compress *)malloc(sizeof(qlz_state_compress));


    // allocate source buffer and read file
    int len1 = sizeof(in_buf);
    printf("压缩前:%d\r\n",len1);

    // allocate "uncompressed size" for the destination buffer
    char *out_buf1 = (char*) malloc(len1);

    // compress and write result
    int len2 = qlz_compress((char*)in_buf, out_buf1, len1, state_compress);
 
    printf("压缩后:%d\r\n",len2);
    for(int i = 0; i < len2; i++)
    {
        printf("%04d ",(unsigned char)out_buf1[i]);
    }
    printf("\r\n");

    int len3 = qlz_size_decompressed(out_buf1);
    printf("需要解压的长度:%d\r\n",len3);
    char *out_buf2 = (char*) malloc(len3);

    int len4 = qlz_decompress(out_buf1, out_buf2, state_compress);

    for(int i = 0; i < len1; i+=2)
    {
        printf("%d ",(unsigned short)out_buf2[i+1]<<8 | (unsigned short)out_buf2[i]&0x00FF);
    }
    printf("\r\n");  
    return 0;

}
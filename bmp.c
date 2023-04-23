#include "bmp.h"
#include <stdio.h>
#include <string.h>

void fillHeaders(FILE *file, int width, int height) {
    uint8_t buf[4];
    int temp;

    memcpy(buf, "BM", 2);
    fwrite(buf, 2, 1, file);

    temp = 122 + width * height * 3;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    temp = 0;
    fwrite(buf, 4, 1, file);

    temp = 122;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);



    temp = 108;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    temp = width;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    temp = height;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    temp = 1;
    memcpy(buf, &temp, 4);
    fwrite(buf, 2, 1, file);

    temp = 24;
    memcpy(buf, &temp, 4);
    fwrite(buf, 2, 1, file);

    temp = 0;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    temp = width * height * 3;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    temp = (int)(width * 39.3700787);
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    temp = (int)(height * 39.3700787);
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    temp = 0;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);
    fwrite(buf, 4, 1, file);

    for (int i = 0; i < 17; i++)
        fwrite(buf, 4, 1, file);

    printf("%ld\n", ftell(file));
}
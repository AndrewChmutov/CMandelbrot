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

    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    fwrite(buf, 4, 1, file);

    temp = 122;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);
}
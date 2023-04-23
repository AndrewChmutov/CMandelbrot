#include "bmp.h"
#include <stdio.h>
#include <string.h>
#include "mandelbrot_functions.h"

void fillHeaders(FILE *file, int width, int height) {
    uint8_t buf[4];
    int temp;

    // --- File Header ---

    // File format
    memcpy(buf, "BM", 2);
    fwrite(buf, 2, 1, file);

    // Size of the file
    // offset + amount of pixels * size of pixel
    temp = 122 + width * height * 3;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    // reserved 
    temp = 0;
    fwrite(buf, 4, 1, file);

    // offset
    temp = 122;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    // ---- Info Header ---

    // header size
    temp = 108;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    // width
    temp = width;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    // height
    temp = height;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    // planes
    temp = 1;
    memcpy(buf, &temp, 4);
    fwrite(buf, 2, 1, file);

    // bit per pixel
    temp = 24;
    memcpy(buf, &temp, 4);
    fwrite(buf, 2, 1, file);

    // compression
    temp = 0;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    // size of file without offset
    temp = width * height * 3;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    // XPelsPerMeter
    temp = 2835;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    // YPelsPerMeter
    temp = 2835;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);

    // ColorUsed and ColorImportant
    temp = 0;
    memcpy(buf, &temp, 4);
    fwrite(buf, 4, 1, file);
    fwrite(buf, 4, 1, file);

    // padding
    for (int i = 0; i < 17; i++)
        fwrite(buf, 4, 1, file);

}


void pixelByPixelMandelbrot(FILE *file, int width, int height,
                    double minR, double maxR,
                    double minI, double maxI,
                    int maxIterations) {
    int padding = (int)((24 * width + 31) / 32) * 4 - width * 3;
    uint8_t color;
    double cR, cI;

    for (int y = 0; y < height; y++) { // row
        for (int x = 0; x < width; x++) { // pixel
            cR = mapFunction(x, width, minR, maxR);
            cI = mapFunction(y, height, minI, maxI);

            color = findMandelbrot(cR, cI, 200) % 256;

            for (int p = 0; p < 3; p++) // fill RGB
                fputc(color, file);
        }

        // padding
        for (int p = 0; p < padding; p++)
            fputc(0, file);
    }
}
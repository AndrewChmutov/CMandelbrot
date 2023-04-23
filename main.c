#include <stdio.h>
#include <stdlib.h>
#include "safety_functions.h"
#include "bmp.h"


int main(int argc, char **argv) {
    if (argc < 4){
        printf("Required: WIDTH HEIGHT PATH-TO-BMP-FILE\n");
        return 0;
    }

    if (!isInt(argv[1]) || !isInt(argv[2])) {
        printf("Size is not valid.\n");
        return 0;
    }

    int width = atoi(argv[1]), height = atoi(argv[2]);
    double minR = -2, maxR = 1;
    double minI = -1, maxI = 1;

    FILE *file = fopen(argv[3], "wb");

    fillHeaders(file, width, height);
    pixelByPixelMandelbrot(file, width, height, minR, maxR, minI, maxI, 10000);

    fclose(file);
    return 0;
}
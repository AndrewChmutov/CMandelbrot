#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    if (!pathExists(argv[3])) {
        printf("No such path exists.\n");
        return 0;
    }

    int width = atoi(argv[1]), height = atoi(argv[2]);
    int minR = -2, maxR = 1;
    int minI = -1, maxI = 1;

    FILE *file = fopen(strcat(argv[3], "/fractal.bmp"), "wb");

    fillHeaders(file, width, height);

    fclose(file);
    return 0;
}
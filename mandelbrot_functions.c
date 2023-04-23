#include "mandelbrot_functions.h"


double mapFunction (int value, int length, double min, double max) {
    return value * (max - min) / (length) + min;
}


int findMandelbrot(double cR, double cI, int maxIterations) {
    int i = 0;
    double zR = 0.0, zI = 0.0;
    double temp;

    // limit && magnitude
    while (i < maxIterations && (zR * zR + zI * zI < 4.0)) {
        temp = zR * zR - zI * zI + cR;
        zI = 2.0 * zR * zI + cI;
        zR = temp;

        i++;
    }

    return i;
}
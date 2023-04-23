# Mandelbrot fractal

This is the program that draws this fractal in bmp. <br>

## Installation
First, copy the repository and run there cmake as follows:
```
git clone https://github.com/AndrewChmutov/CMandelbrot
cd CMandelbrot
cmake -S . -B build
```
It will make configurations for compilation.<br>
Then, go to directory 'build' and compile it:
```
cd build
make
```

---

## How to use

Template for using the program is:

```
./mandelbrot WIDTH HEIGHT PATH-TO-BMP
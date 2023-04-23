cmake_minimum_required(VERSION 3.2)

project(mandelbrotFractal)

add_executable(mandelbrot main.c safety_functions.c mandelbrot_functions.c bmp.c)
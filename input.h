#ifndef INPUT_H
#define INPUT_H

#include <stdlib.h>
#include <stdio.h>

float Immagin[28][28]; // matrix to take inputs from the image

int read_pixel(FILE *file, float immagine[28][28]);

#endif
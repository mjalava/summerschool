#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"

#define DX 0.01
#define DY 0.01

// Field structure definition
typedef struct {
  int nx,ny;
  float dx,dy;
  float dx2,dy2;
  double **data;
} field;

// Function prototypes
void init_field(field * f);

void init_temp(field * f, float x0, float xmax, float y0, float ymax);

void laplacian(field * f);

void print_field(field * f);

#endif

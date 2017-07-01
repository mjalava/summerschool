#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"
#include "pngwriter.h"


void init_field(field *f)
{
  int i,nx,ny;
  nx = f->nx + 2;
  ny = f->ny +2;

  f->data = malloc(ny * sizeof(double *));
  f->data[0] = malloc(ny *  nx * sizeof(double));
  
    for (i = 0; i < ny; i++)
      f->data[i] = f->data[0] + i * nx;


}

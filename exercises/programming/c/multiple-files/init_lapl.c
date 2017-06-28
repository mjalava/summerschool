#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"
#include "dynamic_array.h"

void init_lapl(field *f)
{
  int i, j, error_code;
  int nx, ny;
  field laplacian;

  nx = f->nx + 2;
  ny = f->ny +2;


  for(i = 1; i < nx - 1; i++)
    {
    for(j = 1; j < ny - 1; j++)
      {
	f->data[i][j] = (f->data[i-1][j] - 2 * f->data[i][j] + f->data[i+1][j]) / f->dx2 + (f->data[i][j-1] - 2 * f->data[i][j] + f->data[i][j+1]) / f->dy2;
      }



    
}

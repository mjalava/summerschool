#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"
#include "dynamic_array.h"

void init_temp(field *f, float x0, float xmax, float y0, float ymax)
{
  int i, j, error_code;
  int nx, ny;

  nx = f->nx + 2;
  ny = f->ny +2;


  for(i = 0; i < nx; i++)
    {
      f->data[i][0] = x0;
      f->data[i][nx-1] = xmax;
    }

    for(j = 0; j < ny; j++)
      {
	f->data[0][j] = y0;
	f->data[nx-1][j] = ymax;
      }



    
}

#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

void init_lapl(field *f)
{
  int i, j, error_code;
  int nx, ny;
  field laplacian;

  nx = f->nx + 2;
  ny = f->ny +2;


  for(i = 0; i < nx - 1; i++)
    {
      f->data[i][0] = 0.0;
      f->data[i][ny-1] = 0.0;
    }


    for(j = 1; j < ny - 1; j++)
      {
      f->data[0][j] = 0.0;
      f->data[nx-1][j] = 0.0;

      }



    
}

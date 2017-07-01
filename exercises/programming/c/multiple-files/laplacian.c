#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"
#include "dynamic_array.h"

void gen_laplacian(field *lf,field *tf)
{
  int i, j;
  int nx, ny;

  nx = tf->nx;
  ny = tf->ny;


  for(i = 1; i <= nx - 1; i++)
    {
    for(j = 1; j <= ny - 1; j++)
      {
	printf("%d %d\n",i,j);
	lf->data[i][j] = (tf->data[i-1][j] - 2 * tf->data[i][j] + tf->data[i+1][j]) / tf->dx2 + (tf->data[i][j-1] - 2 * tf->data[i][j] + tf->data[i][j+1]) / tf->dy2;
      }

    }
}


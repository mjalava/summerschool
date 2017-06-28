#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"
#include "pngwriter.h"


void init_field(field *f)
{
  int i,nx,ny;
  nx = f->nx + 2;
  ny = f->ny +2;

  f->data = malloc(ny * sizeof(float *));
  f->data[0] = malloc(ny *  nx * sizeof(float));
  
    for (i = 0; i < ny; i++)
      f->data[i] = f->data[0] + i * nx;


    


    /*
    // Call the png writer routine
    error_code = save_png((double *) laplacian, NX, NY, "datastructures_functions_heat-a_b.png", 'c');

    if (error_code == 0) {
        printf("Wrote the output file datastructures_functions_heat-a_b.png\n");
    } else {
        printf("Error while writing output file datastructures_functions_heat-a_b.png\n");
    }
    */


}

#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"

#define NX 258
#define NY 258

#define DX 0.01
#define DY 0.01

int main(void)
{
  int i, j, error_code;
    // Add here the definition for array with name 'array'
    // of size NX times NY (258x258)

    double array[NX][NY] = {0};
    double laplacian[NX][NY] = {0};

    for(i = 0; i < NX; i++)
      {
	      array[i][0] = 5.0;
	      array[i][NY-1] = 85.0;
      }

    for(j = 0; j < NY; j++)
	  {
	    array[0][j] = 20.0;
	    array[NX-1][j] = 70.0;
	  }

    //    printf("cell 20,20 is %d\n",array[20][20]);

    // Zero out the outer boundary of laplacian
    for (i = 0; i < NX; i++)
        laplacian[i][0] = laplacian[i][NY - 1] = 0.0;
    for (j = 0; i < NY; j++)
        laplacian[0][j] = laplacian[NX - 1][j] = 0.0;

    


    /*
    // Call the png writer routine
    error_code = save_png((double *) laplacian, NX, NY, "datastructures_functions_heat-a_b.png", 'c');

    if (error_code == 0) {
        printf("Wrote the output file datastructures_functions_heat-a_b.png\n");
    } else {
        printf("Error while writing output file datastructures_functions_heat-a_b.png\n");
    }
    */

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

int main(int argc, char *argv[])
{

    int nx, ny;
    field temperature,laplacian;

    int i;

    // Two command line arguments required
    if (argc != 3) {
        printf
            ("Please give two command line arguments for x- an y-dimensions\n");
        return (-1);
    }
    // atoi function converts a string to integer
    nx = atoi(argv[1]);
    ny = atoi(argv[2]);

    temperature.nx = nx;
    temperature.ny = ny;

    init_field(&temperature);
    init_field(&laplacian);
    init_temp(&temperature,20.0,70.0,5.0,85.0);
    init_lapl(&laplacian);

      // Initialize field and print out the result
      //    init_field(&temperature, nx, ny);
      //print_field(&temperature);
	
	// Free memory allocation
	// TODO: Free memory allocations

    return 0;
}

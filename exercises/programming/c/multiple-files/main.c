#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"
#include "pngwriter.h"
#include <png.h>

int main(int argc, char *argv[])
{

  int nx, ny, error_msg;
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
    gen_laplacian(&laplacian,&temperature);


    error_msg =  save_png(laplacian.data[0], laplacian.ny, laplacian.nx, "output.png", 'c');


    return 0;
}

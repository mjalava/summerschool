/* Main solver routines for heat equation solver */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <mpi.h>
#include <omp.h>

#include "heat_nonblock.h"

/* Exchange the boundary values */
void exchange(field *temperature, parallel_data *parallel, MPI_Request *req)
{

    /* TODO start: implement halo exchange */
    // Send to the up, receive from down
  //  int my_y0 = (parallel->rank * temperature->ny) + 1;
  //int my_yn = my_y0 + temperature->ny;
  int bs = temperature->ny+2;
  MPI_Status status;


  //PLEASE NOTE!! Up and down are reversed, as M.J. got the indices wrong
  //compared to the code!

    MPI_Isend(temperature->data[temperature->nx], bs, MPI_DOUBLE,
	      parallel->ndown, 1, MPI_COMM_WORLD,&req[0]);

    MPI_Irecv(temperature->data[0], bs, MPI_DOUBLE, 
	       parallel->nup, 1, MPI_COMM_WORLD,&req[1]);


    // Send to the down, receive from up
  MPI_Isend(temperature->data[1], bs, MPI_DOUBLE, parallel->nup,
	       0, MPI_COMM_WORLD,&req[2]);

  MPI_Irecv(temperature->data[temperature->nx+1], bs, MPI_DOUBLE,
	       parallel->ndown, 0, MPI_COMM_WORLD,&req[3]);

    /* TODO end */
}


/* Update the temperature values using five-point stencil */
void evolve(field *curr, field *prev, double a, double dt, MPI_Request *req)
{
    int i, j;
    double dx2, dy2;
    MPI_Status stat[4];

    /* Determine the temperature field at next time step
     * As we have fixed boundary conditions, the outermost gridpoints
     * are not updated. */
    dx2 = prev->dx * prev->dx;
    dy2 = prev->dy * prev->dy;
    //#pragma omp parallel for private(i,j) //OpenMP + MPI too complex with non-blocking
    for (i = 2; i < curr->nx; i++) {
        for (j = 1; j < curr->ny + 1; j++) {
            curr->data[i][j] = prev->data[i][j] + a * dt *
                               ((prev->data[i + 1][j] -
                                 2.0 * prev->data[i][j] +
                                 prev->data[i - 1][j]) / dx2 +
                                (prev->data[i][j + 1] -
                                 2.0 * prev->data[i][j] +
                                 prev->data[i][j - 1]) / dy2);

	    
	    
	    /*    for (i = 1; i < curr->nx + 1; i++) {
        for (j = 1; j < curr->ny + 1; j++) {
            curr->data[i][j] = prev->data[i][j] + a * dt *
                               ((prev->data[i + 1][j] -
                                 2.0 * prev->data[i][j] +
                                 prev->data[i - 1][j]) / dx2 +
                                (prev->data[i][j + 1] -
                                 2.0 * prev->data[i][j] +
                                 prev->data[i][j - 1]) / dy2);*/

	}
    }
    MPI_Waitall(4,req,stat);
    for(i = 1; i < curr->nx + 1; i+=curr->nx-1) {
    for (j = 1; j < curr->ny + 1; j++) {
      curr->data[i][j] = prev->data[i][j] + a * dt *
	((prev->data[i + 1][j] -
	  2.0 * prev->data[i][j] +
	  prev->data[i - 1][j]) / dx2 +
	 (prev->data[i][j + 1] -
	  2.0 * prev->data[i][j] +
	  prev->data[i][j - 1]) / dy2);
    }
    }
}



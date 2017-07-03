#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int rank;
    int array[8][8];
    //TODO: Declare a variable storing the MPI datatype 
    int mpi_vec;
    MPI_Status status;
    int i, j;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Initialize arrays
    if (rank == 0) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                array[i][j] = (i + 1) * 10 + j + 1;
            }
        }
    } else {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                array[i][j] = 0;
            }
        }
    }


    //TODO: Create datatype that describes one column. Use MPI_Type_vector.
    MPI_Type_vector(8,1,8,MPI_INT,&mpi_vec);
    MPI_Type_commit(&mpi_vec);
    //TODO: Send first column of matrix form rank 0 to rank 1
    if(rank == 0)
      MPI_Send(array,1,mpi_vec,1,99,MPI_COMM_WORLD);
    if(rank == 1)
      MPI_Recv(array,1,mpi_vec,0,99,MPI_COMM_WORLD,&status);

    //TODO: free datatype

    // Print out the result on rank 1
    // The application is correct if the first column has the values of rank 0
    if (rank == 1) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                printf("%3d", array[i][j]);
            }
            printf("\n");
        }
    }
    


    MPI_Finalize();

    return 0;
}

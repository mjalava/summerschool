#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{

  int rank,ncomms;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD,&ncomms);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  printf("Hello world from %d!\n",rank);
  if(rank == 0)
    printf("Total %d mpi processes\n",ncomms);

  MPI_Finalize();
    return 0;
}

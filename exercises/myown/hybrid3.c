#include <stdio.h>
#include <omp.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
  int required = MPI_THREAD_MULTIPLE, provided;
  MPI_Init_thread(&argc,&argv,required,&provided);

  int mpi_id,mpi_size;

  MPI_Comm_rank(MPI_COMM_WORLD,&mpi_id);
  MPI_Comm_size(MPI_COMM_WORLD,&mpi_size);

  if(required > provided)
    {
      MPI_Finalize();
      printf("Error, required = %d, provided = %d\n",required,provided);
      return -1;
    }

#pragma omp parallel
  {
    int omp_id = omp_get_thread_num();
    int task0omp_id = 99;
    if(mpi_id == 0)
      for(int i = 1; i < mpi_size; i++)
	{
	  printf("send %d\n",i);

	  MPI_Send(&omp_id,1,MPI_INT,i,omp_id,MPI_COMM_WORLD);
	}
    else
      {
	MPI_Recv(&task0omp_id,1,MPI_INT,0,omp_id,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
	printf("recv %d\n",omp_id);
      }

    if(mpi_id > 0)
      printf("I'm thread %d in task %d and got %d from task 0\n",
	     omp_id,mpi_id,task0omp_id);
  }

  MPI_Finalize();
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <mpi.h>

#define DATASIZE   64
#define WRITER_ID   0

void single_writer(int, int *, int);


int main(int argc, char *argv[])
{
    int my_id, ntasks, i, localsize;
    int *localvector;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

    if (ntasks > 64) {
        fprintf(stderr, "Datasize (64) should be divisible by number "
                "of tasks.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    if (DATASIZE % ntasks != 0) {
        fprintf(stderr, "Datasize (64) should be divisible by number "
                "of tasks.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    localsize = DATASIZE / ntasks;
    localvector = (int *) malloc(localsize * sizeof(int));

    for (i = 0; i < localsize; i++) {
        localvector[i] = i + 1 + localsize * my_id;
    }

    single_writer(my_id, localvector, localsize);

    free(localvector);

    MPI_Finalize();
    return 0;
}

void single_writer(int my_id, int *localvector, int localsize)
{
    FILE *fp;
    int *fullvector;
    int i, ntasks;

    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);

    if(my_id == WRITER_ID)
      {
	fullvector = (int *) malloc(DATASIZE * sizeof(int));
	for(i = WRITER_ID*localsize; i < (WRITER_ID+1)*localsize; i++)
	  fullvector[i] = localvector[i];
      }

    for(i = 0; i < ntasks; i++)
      {
	printf("%d\n",i);
	if(i != WRITER_ID && my_id == WRITER_ID)
	  MPI_Recv(fullvector + i * localsize,localsize,MPI_INT,i,99,
		   MPI_COMM_WORLD,MPI_STATUS_IGNORE);
	else if(i != WRITER_ID && my_id == i)
	  MPI_Send(localvector,localsize,MPI_INT,WRITER_ID,99,MPI_COMM_WORLD);


      }


    if(my_id == WRITER_ID)
      {
	fp = fopen("outfile","w");
	for(i = 0; i < DATASIZE; i++)
	  {
	    fprintf(fp,"%d %d\n",i,fullvector[i]);
	  }
      }

    /* TODO: Implement a function that will write the data to file so that
       a single process does the file io. Use rank WRITER_ID as the io rank */
    
    if(my_id == WRITER_ID)
      free(fullvector);
}


#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
  int i, myid, ntasks, count;
    int size = 10000000;
    int *message;
    int *receiveBuffer;
    MPI_Status status;

    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message */
    message = malloc(sizeof(int) * size);
    receiveBuffer = malloc(sizeof(int) * size);
    /* Initialize message */
    for (i = 0; i < size; i++)
        message[i] = myid;

    /* Start measuring the time spend in communication */
    MPI_Barrier(MPI_COMM_WORLD);
    t0 = MPI_Wtime();

    /* TODO start */
    /* Send and receive messages as defined in exercise */

    int right = myid + 1;
    int left = myid -1;
    if(right == ntasks)
      right = MPI_PROC_NULL;
    if(left < 0)
      left =  MPI_PROC_NULL;
      MPI_Sendrecv(message,size,MPI_INT,right,0,receiveBuffer,size,MPI_INT,left,0,MPI_COMM_WORLD,&status);

      MPI_Get_count(&status,MPI_INT,&count);

        printf("Sender: %d. Sent elements: %d. Tag: %d. Receiver: %d\n",
               myid, size, 0, right);

        printf("Receiver: %d. first element %d. count %d.\n",
               myid, receiveBuffer[0],count);
    

    /* TODO end */

    /* Finalize measuring the time and print it out */
    t1 = MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);
    fflush(stdout);

    printf("Time elapsed in rank %2d: %6.3f\n", myid, t1 - t0);

    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}

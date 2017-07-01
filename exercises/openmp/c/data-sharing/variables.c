#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

int main(void)
{

    int var1 = 1, var2 = 2;
    int omp_rank;
 
    /* TODO:
     *   Test the effect of different data sharing clauses here
     */
#pragma omp parallel shared(var1,var2) private(omp_rank)
    {
      omp_rank = omp_get_thread_num();


        printf("Region 1: var1=%i, var2=%i\n", var1, var2);
#pragma omp critical
        var1++;
#pragma omp single
        var2++;

    }
    printf("After region 1: var1=%i, var2=%i\n\n", var1, var2);

    return 0;
}

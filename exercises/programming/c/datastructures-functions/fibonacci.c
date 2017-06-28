#include <stdio.h>

int main(int argc, char *argv[])
{
   // declare array and loop variable
   int f[20];
   int i;

   // initialize necessary array elements and write the for loop

   int n;

  
   // initialize variables and write the while loop
   // Remember to update all variables within the loop


   f[0] = 0;
   f[1] = 1;
   for(n=2; n < 20; n++)
     {
       f[n] = f[n-2] + f[n-1];
     }


   printf("First 20 Fibonacci numbers are:\n");
   for (i=0; i < 20; i++) {
       printf("%d\n", f[i]);
   }

   printf("\n"); 

   return 0;
}

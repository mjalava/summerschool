#include <stdio.h>

int main(int argc, char *argv[])
{
   int f0, f1, f2;

  
   // initialize variables and write the while loop
   // Remember to update all variables within the loop

   f0 = 0;
   f1 = 1;

   printf("0\n");
   printf("1\n");
   do
     {
       f2 = f0 + f1;
       if(f2 < 100)
	 {
	   printf("%d\n",f2);
	 }
       else
	 {
	   break;
	 }
       f0 = f1;
       f1 = f2;
     }
   while(1);

   return 0;
}

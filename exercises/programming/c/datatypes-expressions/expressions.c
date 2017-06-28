#include <stdio.h>

int main(int argc, char *argv[])
{
   // declare integers, floats, and doubles
	int a = 1;
	float b = 0.1; 
	double c = 1.1;
	double *cp;

	cp = &c;

	printf("sum of all is %f\n",a+b+c);
	printf("sum of all as int is %d\n",a+b+c);
	printf("sum of all as long is %d\n",a+b+c);
	printf("address of float c is %p\n",cp);
	printf("next address is %p\n",++cp);
	

   // evaluate expressions, e.g. c = a + 2.5 * b
   // and print out results. Try to combine integers, floats
   // and doubles and investigate what happens in type conversions

   return 0;
}

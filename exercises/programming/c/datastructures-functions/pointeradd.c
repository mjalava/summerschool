#include <stdio.h>

void add_one_to_both(int *a, int *b)
{
  (*a)++;
  (*b)++;
}


int main(int argc, char *argv[])
{
  int a = 10;
  int b = 20;
  add_one_to_both(&a, &b);
  printf("values are %d and %d\n",a,b);
}

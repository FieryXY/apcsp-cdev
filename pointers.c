#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

   float d = 0.5;
    float e = 1.25;
   printf("Address of d is %p\n", (void*) &d);
   printf("Address of e is %p\n", (void*) &e);
   float *dp = &d;
   float *de = &e;
    float temp = *dp;
     *dp = *de;
	*de = temp;

}

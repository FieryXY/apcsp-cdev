#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char b = 'a';
  printf("char b value: %d and size: %lu bytes\n", b, sizeof(b));

  float c = 2.57f;
  printf("float c value: %f and size: %lu bytes\n", c, sizeof(c));

  double d = 2.5789;
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));

 unsigned char byte = 250;
 printf("unsigned char byte value: %cu and size: %lu bytes\n", byte, sizeof(byte));

 long long int e = 1000;
 printf("long long int e value: %llu and size: %lu bytes\n", e, sizeof(e)); 
}


#include <stdio.h>

int main()
{
  int a;
  int b = 3;
  int c;

  a = 2;
  c = a + b;
  printf("Sum of %d and %d is %d\n", a, b, c);
 int temp = a;
 a = c;
 c = temp;
 printf("a is %d and c is %d\n", a, c);
}

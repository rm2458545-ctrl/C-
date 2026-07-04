#include <stdio.h>

int main()
{
  int a  = 10;
  --a;
  printf("a = %d\n", a);

  int b = 20 ;
  printf("b = %d\n ", b++);
  printf("b = %d\n ", b );
  
  return 0;
}

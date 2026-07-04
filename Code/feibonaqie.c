#include <stdio.h>
int main()
{
  int x1 = 1;
  int x2 = 1;
  int x3;
  printf("%d,%d,",x1,x2);
  for(int i = 3; i<=20;i++)
  {
    x3=x1+x2;
    printf("%d,",x3);
    x1 = x2;
    x2 = x3;
  }
  printf("\n");
  return 0;
}

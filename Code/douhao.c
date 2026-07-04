#include <stdio.h>
int main()
{
  int  a, b;
  int  c = 10 ,d = 20;
  a=1, b=2;
   
  int y = (a=10,b=20,c=30);
  printf("y = %d\n",y);
  y = (a=10,b=11,a++);
  printf("y = %d,a=%d\n",y ,a);
  return 0;
}


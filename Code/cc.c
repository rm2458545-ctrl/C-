#include <stdio.h>
int main()
{
  int a;
  int b;
  int c;
  int x;
  int count = 0 ;

  for ( x =100;x <= 999;x++)
    {
    a = x % 10 ;
    b = x / 10 % 10 ;
    c = x / 100 % 10 ;  
    if(a*a*a+b*b*b+c*c*c == x)
    {
    printf(" x=%d ",  x);
    count++;
    }
  }
   printf("水仙花数：%d\n",count);

  printf("\n");


  return 0;
}

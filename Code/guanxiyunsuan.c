#include <stdio.h>
#include <math.h>
int main()
{
  int a = 50 ;
  int b = 99 ;
  double c  = 66.6 ;
  double d  = 22.2 ;
  printf("%d\n" , a!=b);
  printf("%d\n" , b<=c);
  printf("%d\n" , a==b);
  printf("%d\n" , d>=c);
  printf("%d\n" , a<=d);
  printf("%d\n" , b==d);

  float e = 11.1 ;
  double f = 11.1;
  printf("%d %d %d\n", e==11.1 ,f==11.1, e==f);
  printf("%d\n",fabs(e-f)>0.000000000001);
  return 0;
}

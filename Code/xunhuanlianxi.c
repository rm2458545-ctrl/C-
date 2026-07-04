#include <stdio.h>
#include <math.h>
int main()
{
/*  double pi,sum=0;
  int i = 1;
  double f = 1;
  double t;
  do
  {
    t = f/(i*2-1);
    sum += t;
    f = -f;
    i++;
  }while(fabs(t)>=1.0e-6);
  pi  = sum*4;
  printf("pi=%.10lf\n",pi);*/



  double sum=0, f=1, t;
  int i=1;
    while(1)
    {
        t = f/(2*i-1);
        if(fabs(t) < 1e-6) break;
        sum += t;
        f = -f;
        i++;
    }
    printf("pi=%.10lf", sum*4);
    return 0;
}

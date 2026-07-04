//需求：计算1/(2*3)+1/(3*4)+....+1/(n*(n+1))，直到最后一项的值小于0.00001为止。
#include  <stdio.h>
int main()
{

 double sum  = 1.0;
 double last;
 int n = 2;
 do{
   last = 1.0 / (n*(n+1));
   sum +=  last;
   n++;
 }while(last>=0.00001);
  printf("数列之和=%lf\n",sum);
  return 0;
}

#include <stdio.h>
#define pi 3.1415926
double r(double r)
{
  
 double volume = 4.0/3.0*pi*r*r*r;
 return  volume;
}


int main()
{
  double R;
  printf("请输入球的半径：");
  scanf("%lf",&R);


  double vol = r(R);
  printf("球的体积是：%lf\n",vol);
  return 0;



}

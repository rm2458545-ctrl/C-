//编写一个函数，输入四个数据分别表示2个点的x，y坐标，返回两点之间的距离；
#include <stdio.h>
#include <math.h>
double  juli(double  x1,double x2,double y1,double y2)
{

 double dx = x2-x1;
 double dy = y2-y1;
 double L = sqrt(dx*dx+dy*dy);

 return  L;
}
int main()
{
  double a,b,c,d;
  scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
  printf("%lf\n",juli(a,b,c,d));
   return 0;
}

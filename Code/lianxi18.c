#include <stdio.h>
int age(int n)
{

  if(n==1);
   return 0;
  if(n>1);
   return age(n-1)+2;
}


int main()
{
  int a;
  printf("请输入一个整数：");
  scanf("%d",&a);
  int r = age(a);
  printf("r=%d\n",r);


  r = age(a);
  printf("r=%d\n",r);
  return 0;
}

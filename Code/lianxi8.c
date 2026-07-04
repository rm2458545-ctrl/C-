#include <stdio.h>
int cmp(int a,int b,int c);
int sum(); 
int getmax;
void sum2();
int main()
{
  int m ,n,q;
  printf("请输入三个数字：");
  scanf("%d %d %d" , &m,&n,&q);
  printf("最小数字是=%d\n",cmp(m, n,q));
  getmax;
  sum2(); 
  return 0;
}
int cmp(int a,int b,int c)
{
  if(a<b&&b<c)
    return a;
  else if(b<a&&a<c)
    return b;
  else
    return c;
 
}
 int sum()
{ 

  int a =10;
  int b =20;
  int c =a + b;
  printf("sum c = %d\n",c);
  return c;
}
 void sum2()
{
  int e =10;
  int y = 5;
  int o = e + y;
  printf("sum2=%d\n", o);
  return ;
}

int  getmax(int l,int z);
{
  printf("请输入两个数字:\n");
  scanf("%d %d",l,z )
  int k = l>z?l:z;
  printf("最大的数字是：%d",k);  
  return k;
}
















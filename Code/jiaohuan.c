#include <stdio.h>
int main()
{
  int a = 0;
  int b = 0;
  int temp;
  printf("请输入两个整数：\n");
  scanf("%d %d",&a ,&b);
  if (a>b)
  {
    temp = a;
    a = b;
    b =temp;
    printf("%d %d\n",a,b);
  }
  else 
  {
    printf("%d %d\n",a,b);
  }
  return 0;

}

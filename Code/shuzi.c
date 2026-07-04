#include  <stdio.h>
int main()
{
  int x = 0;
  printf("请输入一个数字：");
  scanf("%d",&x);
  printf("x=%d\n",x);
  int count = 1;
  int y = x;
  while((y = y /10) != 0)
  {
    count++;
  }
  printf("%d这个数字是%d位数\n",x,count);

  int  b  = 0;
  printf("请数一个数字：");
  scanf("%d",&b);


  int a = b;
  while(a != 0)
  {
    printf("%d,", a%10);
    a =  a / 10;
  }
  printf("\n");

  return 0;

}

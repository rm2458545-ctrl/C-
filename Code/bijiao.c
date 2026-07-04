#include <stdio.h>
int main()
{
  int a = 0;
  int b = 0;
  int c = 0;
  printf("请输入三个数：");
  scanf("%d %d %d",&a ,&b, &c);
  if(a>b)
  {
    if(a>c)
    {
      printf("最大值是=%d\n",a);

    }
    else
    {
      printf("最大值是=%d\n",c);

    }

  }
  if(a<b)
  {
    if(b>c)
    {
      printf("最大值是=%d\n",b);

    }
    else
    {
      printf("最大值是=%d\n",c);

    }
    }

    return 0;
}



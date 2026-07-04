#include <stdio.h>
int add(void);
int main()

{
  
  int x = add();
  printf("%d\n",x);
  return 0;
}

int  add(void)
{
  int n =10;
  int sum = 0;
  for (int i=1 ;i<=n;i++)
  {
  sum += i;
  }
   return sum;
}
#include <stdio.h>

/*int add(void);

int main()
{
    int x = add(); // 接收返回的总和
    printf("1~10累加总和：%d\n", x);
    return 0;
}

int add(void)
{
    int n = 10;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum; // 有返回值函数才能return数值
}*/

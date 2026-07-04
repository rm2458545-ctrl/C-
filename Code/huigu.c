/*#include <stdio.h>
int main()
{
  int a = 0;
  int b = 0;
  int c = 0;
  printf("请输入三个数：");
  scanf("%d %d %d",&a,&b,&c);

  if (a>=b)
  {
    if (b>=c)
    {
      printf("三个从小到大排序：%d %d %d\n",c,b,a);
      }
    if (a<=c&&c<=b)
    { 
    printf("三个从小到大排序：%d %d %d\n",b,a,c);
    }
  }
  if (a<=b)
  {
    if (a<=c&&b<=c)
    {
      printf("三个从小到大排序：%d %d %d\n",a ,b,c);
      }
    if (a>=c&&c<=b)
    { 
    printf("三个从小到大排序：%d %d %d\n",c,a,b);
    }
  }


  return 0;
}
*/
#include <stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    printf("请输入三个数：");
    scanf("%d %d %d",&a,&b,&c);

    if (a >= b)
    {
        if (b >= c)
        {
            printf("三个从小到大排序：%d %d %d\n", c, b, a);
        }
        else if (a <= c && c <= b)
        {
            printf("三个从小到大排序：%d %d %d\n", a, c, b);
        }
        else
        {
            printf("三个从小到大排序：%d %d %d\n", b, a, c);
        }
    }
    else 
    {
        if (a <= c && b <= c)
        {
            printf("三个从小到大排序：%d %d %d\n", a ,b ,c);
        }
        else if (a >= c && c <= b)
        {
            printf("三个从小到大排序：%d %d %d\n", c, a, b);
        }
        else
        {
            printf("三个从小到大排序：%d %d %d\n", a, c, b);
        }
    }
    return 0;
}








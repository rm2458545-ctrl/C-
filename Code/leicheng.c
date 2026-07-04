#include <stdio.h>

int main()
{
 /* int result = 1;
  int i = 1;
  int n  ;
  printf("请输入一个整数：");
  scanf("%d",&n);
  

  do
  {
    result*=i;
    i++;
  }
  while(i<=n);
  printf("%d\n",result);
*/
 /* double result = 1;
  int i = 1;
  int n ;
  printf("请输入一个整数：");
  scanf("%d",&n);


  while(i<=n)
  {
  result*=i;
  i++;
  }
  printf("%lf\n",result);
*/

  int i ;
  int sum = 0;
  for(i = 2; i<=100; i+=2)
  { 
    sum += i;
  }
  printf("sum=%d\n",sum);
  return 0;
}



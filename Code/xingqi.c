#include <stdio.h>
int main()
{
  int a = 0;
  printf("今天是星期几：");
  scanf("%d",&a);
  if(a==1)
  {
    printf("今天是星期一\n");
  }
  else  if(a==2)
  {
    printf("今天是星期二\n");
  }
  else if(a==3)
  {
    printf("今天是星期三\n");
  }
  else if(a==4)
  {
    printf("今天是星期四\n");
  }
  else if(a==5)
  {
    printf("今天是星期五\n");
  }
  else if(a==6)
  {
    printf("今天是星期六\n");
  }
  else if(a==7)
  {
    printf("今天是星期七\n");
  }

  return 0;
}

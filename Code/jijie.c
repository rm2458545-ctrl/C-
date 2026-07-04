#include <stdio.h>
int main()
{
  int month = 0;
  printf("请输入一个月份：");
  scanf("%d",& month);
  switch(month)
  {
    case 3:
    case 4:
    case 5:
    printf("春天\n");
    break;
    case 6:
    case 7:
    case 8:
    printf("夏天\n");
    break;
    case 9:
    case 10:
    case 11:
    printf("秋天\n");
    break;
    case 12:
    case 1:
    case 2:
    printf("冬天\n");
    break;
  }
 return 0 ; 
}

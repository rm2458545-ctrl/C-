//数组的定义和初始化
#include <stdio.h>
int main()
{
  int arr1[10] = {1,2,3,4,5,6,7,8,9,10};

  printf("arr1[0] = %d\n",arr1[0]);

  int arr[3] = {11,22,33};
  for(int i = 0;i<3;i++)
  {
    printf("%d\n",arr[i]);
  }

  for(int i = 0;i<3;i++)
  {
      arr[i] = 10+i;

  }
  for(int i = 0;i<3;i++)
    printf("%d\n",arr[i]);



  return 0;
}

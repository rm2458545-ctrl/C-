#include <stdio.h>
int main()
{
  int arr[5];

  int i; 
  printf("请输入5个数字：\n");
  for (int i =0;i<5;i++)
  {
    scanf("%d",&arr[i]);

  }
      int max = arr[0];
      int min = arr[0];

      for(int i = 1;i<5;i++)
      {
        if(arr[i]>max)
        {
          max =arr[i];
        }
        if(arr[i]<min)
        {
          min = arr [i];
        }

      }
      printf("数组元素：\n");
      for (int i = 0; i<5;i++)
      {
        printf("%d\n",arr[i]);
      }
    printf("最大值=%d\n",max);
    printf("最小值=%d\n",min);
 


  return 0;
}

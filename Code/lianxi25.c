#include <stdio.h>

void test1()
{
  int a[2][3] = {{11,22,66},{33,88,99}};
  int(*p)[3];
  p = a;
  printf("%d%d\n",a[1][0],p[1][2]);
}

void test2(char (*arr)[2],int len)
{
  printf("%p\n",arr);
  for(int i =0;i<len;i++)
  {
    for(int j =0;j<2;j++ )
    {

      printf("%d,\n",*(*(arr+i)+j));
    }
  }
}




int main()
{ 
  test1();
  char arr[][2] = {0};
  char (*p) [2];
  test2(arr,1); 
  return 0;
}






















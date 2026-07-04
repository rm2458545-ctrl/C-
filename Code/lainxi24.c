#include <stdio.h>

void test1()
{
  int arr[5]={11,22,66,0,99};
  int *p = arr;
  printf("%d\n",*(p+2));
  printf("%d\n", p[2]);
  printf("%d\n", arr[2]);
  printf("%d\n",*(arr+2));
}

void test5(double* arr,int len)
{
  for(int i = 1; i<len ;i++)
  {
    printf("%lf\n",*(arr+i));
  }
}


int main()
{
   test1();
   
   return 0;
} 

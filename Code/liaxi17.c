#include <stdio.h>
//void test(int*arr)
void test(int arr[])
{
 printf("sizeof(arr) = %zu\n",sizeof(arr));
 printf("sizeof(int*)= %zu\n",sizeof(int*));
}
 int main()
{
 int arr[10] = {0};
 printf("sizeof(arr)=%zu\n",sizeof(arr));
 return 0;
}

#include <stdio.h>
int main()
{
 int arr[4];
 printf("%p",arr);
 for(int i = 0;i<4;i++)
 {
   printf("%p,",&arr[i]);


 }
 
  printf("\n");
  return 0;


}

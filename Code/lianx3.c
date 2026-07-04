#include <stdio.h>
int main()
{ 

  short arr[3][4];
  printf("arr%p\n",arr);

  for(int i = 0;i<3;i++)
  {

    printf("arr[%d]:%p---",i,arr[i]);
  
    for(int j=0;j<4;j++)
    {
      printf("arr[%d][%d]:%p,",i,j,&arr[i][j]);
    }
  }
   printf("\n");








  return 0;



}

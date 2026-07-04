#include  <stdio.h>
#include  <time.h>
#include  <stdlib.h>

int main()
{
  srand(time(NULL));
  int i = 1;
  int j = 1 ;
  int x,y;
  i=rand()%10+1;
  j=rand()%10+1;
  printf("%d,%d\n",i,j);  
  int arr[i][j];
  for(x=0;x<i;x++)
  {
    for(y=0;y<j;y++)
    {
      
      arr[x][y]= rand()%10;
      printf("%d ",arr[x][y]);
    }
    printf("\n");
  }



  return 0;
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
  srand(time(NULL));

  int a;
  int b;
  a = rand()%10+1;
  b = rand()%10+1;


  int arr[a][b];
  int count =1;
  printf("%ls\n",&arr[a][b]);
  for(int i = 0;i<a;i++)
  { 
    for(int j=0;j<b;j++)
    {
      arr[a][b] = count++;
  
        
      printf("%d\n",count);
  }
  }
  return 0;
}

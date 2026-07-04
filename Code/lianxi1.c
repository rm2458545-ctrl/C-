#include <stdio.h>
#include  <time.h>
#include <stdlib.h>
int main()
{ 
  int i ;
  int j;
  srand(time(NULL));

  i=rand()%10+1;
  j=rand()%10+1;
  printf("%d",i);
  printf("%d",j);
  

}

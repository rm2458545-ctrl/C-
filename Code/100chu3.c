#include <stdio.h>
int main()
{
  int sum = 0;
  int x = 3;
  do{
    sum += x;
    x += 3;
  }
  while(x<=100);
  printf("%d\n",sum);
  return 0;
}


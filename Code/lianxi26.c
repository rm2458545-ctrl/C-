#include <stdio.h>
void test()
{ 
  for(int i =0;i<3;i++)
  {
    int*x  = array[i];
  }
  long*arr2[4] = {0} ;
  printf("%p\n",arr2[0]);
}

int main()
{
  test(); 
  return 0;
}

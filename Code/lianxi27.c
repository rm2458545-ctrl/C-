#include <stdio.h>
void test1 ()
{
  int a =10;
  int*p = &a;
  int**w = &p;

  printf("%p,%p\n",*w,&a);
  printf("%d,%d\n",**w,a);


  double**p2 = NULL;
  double b  = 11.1;
  double*arr[] = {0};
  p2 = arr;
  double**p3 = arr;
}

int main()
{
  test1();
  return 0;

}

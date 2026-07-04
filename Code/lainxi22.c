#include <stdio.h>

void test1()
{
 int*p1;
 printf("%lu\n",sizeof(int*));
}
void test2()
{
  int*p1;
  printf("%p\n",p1);
 // *p1 = 5;
 // printf("%d\n",*p1);
   int*p2 = NULL;
   printf("%p\n",p2);
   printf("%ld\n",(long)p2);
   int a = 5;
   p2 = &a;
   printf("%d\n",*p2);
}
void test3()
{ 
  int* p5;
  int arr1[] = {21,232,996};
  printf("%p\n",arr1);
  p5 = arr1;
  *p5 =234;
  printf("%d %d\n",arr1[0],*p5);
}
int main()
{

  test2();
  test1();
  test3();
  return 0;
}

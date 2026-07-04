#include <stdio.h>

void test1()
{

  double a =11.1;
  &a;//变量指针
  double *x = &a;
//定义指针变量并初始化
  double * y = &a;
  double* z =&a;
  long *q;
  long b = 1323L;
  q = &b;
//指针变量定义时也可以用NULL初始化
  char* p1 = NULL;
  char w ='a';
  p1 = &w;

}

void  test2()
{

  int a =10;
  int* p =&a;
  a = 20;
  printf("%d\n",a);
  a = a+2;
  *p = 30;//解引用
  printf("%d\n",*p);  
  printf("%d\n",a);  
}

void test3()
{ 
  char a = 'A';
  char*p = &a;
  *p = 'B';
  printf("%c\n",*p);
}


int main()
{
  int l;
  test1();

  test2();
  test3(l);
  printf("%ls\n",&l);
 return 0;
}

#include <stdio.h>

char fun3(char*x,int y )
{
  return 'A';

}

void fun1 ()
{
 long(*p)(int,float,char)
  p = fun3;
  void (*p)();
  p = fun3;
  void(*p3)(char*,int) = fun3;
  char(*p)(char*,int);
  p = p3;
  return 0;

}





int main()
{
  fun1 ();

  return 0;

}















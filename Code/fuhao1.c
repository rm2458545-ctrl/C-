#include <stdio.h>
int  main()
{
  int a = 2;
  int b = 3;
  int c = 4;
  int d = (a+=2)*(b = a + 1)+(c -= 2);
  int result1 = a << 1 + b;
  int x = 5;
  int y = 0;
  y = x > 3 && (x=10);
  int max = a > b ? a:c >c>d?c:b>a?b:d;
  int result2 = (a = b +c)&&(d = a+1)||(c = b+d)&&(b= a -1);
  int p = 10;
  printf("p=%d\n", p += p -= p *p);
  printf("x=%d\n " ,x);
  printf("y=%d\n " ,y);
  printf("d=%d\n " ,d);
  printf("max=%d\n " ,max);
  printf("result=%d\n " ,result2);
  return 0;
}

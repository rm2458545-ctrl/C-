#include <stdio.h>


int main()
{
  short p = 10;
  short a=-10;
  printf("%d,%d,%d\n",~a,~10,~(a+1));
  short b = 26;
  printf("%d\n",a&b);
  printf("%d\n",a>>b);
  printf("%hd\n",a<<12);
  printf("%d\n",a|b);
  printf("%d\n",a^b);
  printf("%d\n",a>>3);
  p&=3;
//  printf("p=%d\n",p);
  p|=3;
//  printf("p=%d\n",p);
  p^=3;
 // printf("p=%d\n",p);
  p<<=3;
  printf("p=%d\n",p);
  p>>=3;
 // printf("p=%d\n",p);

  return 0;
}

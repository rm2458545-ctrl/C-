#include <stdio.h>
int main()
{
  unsigned char d;
  char u;
  u = 499;
  d = 499;
  printf("d = %d\n",d);
  printf("d = %u\n",d);
  printf("u = %d\n",u);
  printf("u = %u\n",u);
  
  short e = 33333;
  unsigned short f = -66666;
  printf("%hd, %hu\n",e ,e);
  printf("%hd, %hu\n",f ,f);
  printf("%d, %u\n",f ,f);
  printf("%d, %u\n",e ,e);
  printf("%hhd, %hhu\n",e ,f);
  printf("%hhd, %hhu\n",f ,f);

  return 0;
}


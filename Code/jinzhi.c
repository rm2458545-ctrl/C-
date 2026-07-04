#include <stdio.h>
int main()
{
	int a = 255;
	printf("a: %d\n", a);
	printf("a: %o\n", a);
	printf("a: %x\n", a);
	printf("a: %X\n", a);

	unsigned int b = 254;
	printf("b: %u\n", b);

	printf("a: %+d\n", a);
	a = -23;
  printf("a: %-d\n", a);
  printf("a: % d\n", a);
	printf("a: %d\n", a);

	short d = 32767;
	printf("%hd\n", d);
	printf("%hu\n", d);
	d = 3276;
	printf("%hd\n", d);
	printf("%hu\n", d);
 

  int c =0b10100011;
  printf("%d\n",c);
  int n = 01234567;
  printf("%d , %o\n",n ,n);
  int z = 0x1A3CDF;
  printf("%d , %x\n",z ,z);

  return 0;
}

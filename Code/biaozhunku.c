#include <stdio.h> 
#include <limits.h> 
#include <float.h>

#define PI  3.1415

int main()
{
	int a = 65;
	printf("%d\n", 65);
	printf("%c\n", 65);
	printf("%c\n", 97);
	printf("%c\n", 48);
	printf("%c\n", 57);

	char b = 'A';
	b = 66;
	printf("%c, %d, %hhd\n", b, b, b); 
	printf("%lu, %lu\n", sizeof(char), sizeof b);
	printf("%d, %d\n", INT_MIN, INT_MAX);
	printf("%u\n", UINT_MAX);
	printf("%hd, %hd\n", SHRT_MIN, SHRT_MAX);
	printf("%e, %e\n", FLT_MIN, FLT_MAX);
	printf("%E, %E\n", DBL_MIN, DBL_MAX);
	return 0;
}


#include <stdio.h>
int main()
{
  double a = 99.5;
  printf("%lf\n", a += 0.5);
  printf("%lf\n", a -= 0.5);
  printf("%lf\n", a *= 0.5);
  printf("%lf\n", a /= 0.5);
  printf("%lf\n", a -=   2);

  double b = 22.2;
  int c = 5;
  printf("%lf\n", b += c);
  printf("%lf\n", b -= c);
  printf("%lf\n", b *= c);
  printf("%lf\n", b /= c);
  return 0;
}

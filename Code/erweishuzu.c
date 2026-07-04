#include <stdio.h>
int main()
{ 

  int a[2][9];
  double d[2][2] = {{66.6,99.9},{55.5,11.4}};

  unsigned  char  h[][3] ={'a','b','c'};
  unsigned  short j[][3] = {97,98,99,100};
  printf("%lu,%lu,%lu\n",sizeof j ,sizeof j[0],sizeof j[0][1]);
  return 0;


}

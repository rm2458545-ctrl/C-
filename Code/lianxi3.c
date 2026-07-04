#include <stdio.h>
int main()
{
  char a[]={'a','s' ,'p'};
  char b[]= {"abc"};
  char c[] = {'p','\0'};


  printf("%p,%p\n",a ,b);
  printf("a==b:%d\n",a == b);

  printf("%s\n",b);
  printf("%s\n",c);
  printf("%s\n",a);



  return 0;
}

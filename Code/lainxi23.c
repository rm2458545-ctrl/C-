#include <stdio.h>
void test1()
{
  char arr[] = "abcd";
  char*p = arr;
  int len = strlen(arr);
  for(int i = 0;i<len;i++)
  {
    printf("%c,%c\n",arr[i],p[i]);
  }
}


int main()
{

 test1();
 return 0;
}

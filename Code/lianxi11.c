#include <stdio.h>
char a(char b)
{
  return b - '0';

}


int main(void)
{
  char c;
 printf  ("请输入一个数字字符：");
 scanf   ("%c",&c);

 int num = a(c);
 printf("转换后的数字：%d\n",num);
 return 0;




}

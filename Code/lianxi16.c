#include <stdio.h>
int c(char arr[x], char c)
{
  for(int i = 0;i<x;i++)
  {
      
  }
  
}
int main(void)
{
    char s[100];
    char cha;
    printf("请输入字符串：");
    scanf("%s", s);
    scanf("%s", s);
    printf("请输入要查找的字符：");
    scanf("%c", &cha);

    int num = c(s, cha);
    printf("该字符一共出现 %d 次\n", num);
    return 0;
}

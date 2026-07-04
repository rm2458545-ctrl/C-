#include <stdio.h>
int main(int argc,char **argv)
{
  unsigned int u = 0 ;
  printf("===无符号整数下溢===\n");
  printf("u = %u, u-1 = %u\n", u, u-1);
  signed int s = 2147483647; // int 最大值（2^31 - 1）
  printf("\n=== 有符号整数溢出 ===\n");
  printf("s = %d, s + 1 = %d\n", s, s + 1);

  unsigned int x = 5;
  signed int y = -3;
  printf("\n=== 有符号与无符号混合比较 ===\n");
  if (x > y) {
                printf("x (%u) > y (%d) — 结果正确\n", x, y);
              }
  else {
  printf("x (%u) < y (%d) — 结果异常！因为 y 被当作无符号处理了\n", x, y);

  return 0;
  }
}

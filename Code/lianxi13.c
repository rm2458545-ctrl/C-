#include <stdio.h>
int a(int n)
{
    int sum = 0;
    int d;
    
    while (n > 0)
    {
        d = n % 10;         
        n = n / 10;
        sum += d * d * d;

    }
    return sum;
}

int main()
{
    int q;
    printf("请输入一个整数：");
    scanf("%d", &q);
    int l = a(q);
    printf("各位数字立方和 = %d\n", l);
    return 0;
}

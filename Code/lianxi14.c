#include <stdio.h>
double f(double x)
{
    double a;
    if (x > 5)
    {
        a = 4 * x + 7;
    }
    else
    {
        a = -2 * x + 3;
    }
    return a;
}

int main()
{
    double x, y;
    printf("请输入x的值：");
    scanf("%lf", &x);
    y = f(x);
    printf(" %lf\n", y);
    return 0;
}

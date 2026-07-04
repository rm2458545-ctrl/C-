#include <stdio.h>
int main()
{
    int a;
    printf("请输入整数：");
    scanf("%d", &a);
    printf("a = %d\n", a);

    double b = 1.1;
    printf("请输入小数：");
    scanf("%lf", &b);
    printf("b = %f\n", b);

    char c;
    printf("请输入符号：");
    scanf("%c", &c);
    scanf("%c", &c);
    printf("符号  = %c\n ", c);

    long d;
    printf("请输入长整型数：");
    scanf("%ld", &d);
    printf("d = %ld\n", d);




    return 0;
}
 

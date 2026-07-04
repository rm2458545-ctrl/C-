#include <stdio.h>
int main()
{

    int a = 0;
    printf("请输入一个数字：");
    scanf("%d",&a);

        if (a%2 == 1)
    {
        printf ("这是一个奇数\n");
    }
    else 
    {

        printf("这是个偶数\n");
    }
    return 0;
}

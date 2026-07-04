#include <stdio.h>

int A(int n, int m)
{
    int jiecheng = 1;
    for(int i = 0; i < m; i++)
    {
        jicheng *= (n - i);
    }
    return jiecheng  ;
}

int main()
{
    printf("A(6,2) = %d", A(6,2));
    return 0;
}





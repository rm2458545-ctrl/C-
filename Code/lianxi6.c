#include<stdio.h>
int main()
{
    int max,min,x=2;
  
    scanf("%d",&min);
    while(--x)
    {
        scanf("%d",&max);
        if(max < min)
        {
            min = max;
        }
    }
    printf("最小值：%d",min);
    return 0;
}


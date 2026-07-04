#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{  
   srand(time(NULL));
    int i;
    int max;
    int min;
    int a;
    int arr[5];

    for(i = 0; i < 5; i++)
    {
    
    int  num = rand()%(max-min+1) + min;
    printf("请输入要查找的数字：");
    }
    scanf("%d", &a );

    for(i = 0; i < 5; i++)
    { 
        if(arr[i] == a)
        {
            printf("找到 %d，下标：%d\n", a, i);
        }
    }
    return 0;
}

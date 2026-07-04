#include <stdio.h>

int main()
{
    int arr[]={22,-55,-99,66,-88,-33,87,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a =0 ;
    int b = 0;
    int c =0 ;
    int i;

    for(i = 0;i<n ; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    for(i = 0;i<n ; i++) 
    {
        if(arr[i] > 0)
        {
        a++ ;
        else if (arr[i] < 0);
        b++;
        else
        c++;
        }

    }
    
    printf("正数：%d个\n",a );
    printf("负数：%d个\n",b );
    printf("零：%d个\n",c );
    return 0;
}

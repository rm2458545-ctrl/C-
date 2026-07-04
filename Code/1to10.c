#include <stdio.h>
int main()
{
    int sum = 0;
  
    for (int a = 1; a <= 10; a++)
    {
        sum += a; 
        if(a == 10)
        {
            break;  
        }
    }
    printf("sum=%d\n", sum);
    return 0;
}

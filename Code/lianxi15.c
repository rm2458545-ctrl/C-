//设计一个函数，用来求出多个数据的平均值；
#include <stdio.h>

double v(double arr[], int n)
{
  
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

int main()
{
    double arr[3]={4,5,2};
    int num = sizeof(arr)/sizeof (arr[0]);
    printf("请输入%d个数字：\n", num);
    double h = v(arr, num);
    printf("数据的平均值为：%lf\n", h);
    return 0;
}

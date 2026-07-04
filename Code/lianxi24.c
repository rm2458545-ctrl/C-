#include <stdio.h>
int main(){
    int arr[5] = {11,22,33,44,55};
    int* p = arr;
    int len = sizeof(arr)/sizeof(arr[0]);
    while(p < arr + len)
    {
        printf("%d \n", *p);
        p++;
    }
    return 0;
}
/*#include <stdio.h>
int main(){
    int arr[5] = {11,22,33,44,55};
    int* p = arr;
    for(int i=0; i<5; i++)
    {
        printf("%d ", p[i]);
        // printf("%d ", *(p+i));
    }
    return 0;
  }*/

#include <stdio.h>
int main()

{ 
  double arr [] =  { 44.4 ,  66.2,   212.11, 155, 5.22, 2, 3.36 };
  

  printf("%lu\n",sizeof arr / sizeof arr[0]);
  int length = sizeof arr / sizeof arr[0]; 
  for(int i = 0; i<length ;i++)
  {
    if(arr[i]>0)
      printf("%d",i);

  }



 return 0 ;
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
  srand(time(NULL));
  

  int arr[10];
  int min = -5;
  int max =  3;
  for(int i =0;i<10;i++)
  { 




    arr[i] = rand()%20;


    int num = rand()%(max-min+1) + min;
    printf("num:%d\n",num);

  

  }
      

   int num;
   printf("请输入0～20之间的数字：");
   scanf("%d",&num);

   int index = -1;
   for(int i = 0;i<10;i++)

    {
        if((arr[i])==num)
       {
            index=1;
            break;

       }
    }
    return 0;

}

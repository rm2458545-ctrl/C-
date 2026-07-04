/*#include <stdio.h>
int main()
{ 
   int i;
   int count = 0;
   for(int i=1;i<=100;i++)
   {
    if(i%7==0)
      continue;
  
      printf("%d,",i);
      count++;
    }
   printf("%d",count);
   return 0;
}*/
#include <stdio.h>

int main()
{
    int count = 0;
    for(int i = 1; i <= 100; i++)
    {
      
        if(i % 7 == 0 || i % 10 == 7 ||i / 10 == 7)
        {
            continue;
        }
        printf("%d,", i);

        count++;

        if(count % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("%d\n", count);



  return 0;
}


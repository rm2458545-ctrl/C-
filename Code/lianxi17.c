#include  <string.h>
#include  <stdio.h>
int main()
{

  char  str [10] ="hello";
  char  sts[4][10] ={"hello ", "world" ,"yueqian"};
  char max[10];
  strcpy(max,sts[0]);

for(int i =1 ;i<4;i++)
{
  if (strcpy(max,sts[i],max)>0)
    strcpy(max,sts[i]);


}



  printf("max :%s\n",max);

 return 0;

}

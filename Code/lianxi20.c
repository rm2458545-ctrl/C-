#include <stdio.h>
int getmax(int,int);
int a(int,double);


int getmax(int a,int b)
{
  return a>b?a:b;
}





int getmax2(int x,int y,int z)
{
 return getmax(getmax(x,y),z);
}






void getmax3()
{
  int  x,y,z;
  scanf("%d%d%d",&x,&y,&z);
  int t =x>y?x:y;
  t = t>z?t:z;
  printf("getmax:%d\n",t);
} 





int getmax5(int a,int b,int c)
{
  printf("getmax\n");
  return getmax(getmax(a,b),c);
}


int main()
{


  getmax3();

  return 0;
}


#include <stdio.h>
#include <string.h>
int main()
{

  char str[10]  ;
  char src[] = "hello";
  char dest[] = "wrold";
  fgets(str,sizeof str, stdin);

//去除回车符\n
  str[strlen(str)-1]='\0';



  puts(str);
  printf("%s\n",str);
//数组遍历
  for(int i =0;i<15;i++)
  {

    printf("%s",str);

  }
  
   printf("\n");
   strcat(dest,src);
   puts(dest);
   


   size_t n = strlen(str);
   printf("%ld\n",n);

  return 0;
}

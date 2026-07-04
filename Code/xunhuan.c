#include <stdio.h>
int main()
{
  int score = 0;
  printf("请输入小明的考试成绩：");
  scanf("%d" , &score);
  printf("score = %d\n", score);

 /* if (score >= 60)
  {
        printf("带小明去游乐场\n");
  }
  else 
  {
        printf("不带小明去游乐场\n");
  }*/
     if (score >= 90)
     {
        printf("带小明去迪士尼游乐园\n");
     }
     else if (score >= 80)
    {
      printf("带小明去广州长龙游乐园\n");
    }
    else if(score>=70)
        {
          printf("带小明去游乐园\n");
        } 
     else if(score>=60)
     {
        printf("带小明去小区玩\n");
     }
     else 
     {
        printf("打屁股\n");
     }
    return 0 ;
}

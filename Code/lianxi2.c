#include <stdio.h>
int main()
{
  int score[3][4]= {
    {58,66,96,36},
    {99,55,77,66},
    {78,99,82,45}
 };
  for(int i=0;i<3;i++)
  {
   int sum = 0;
   for(int j =0;j<4;j++)
   {

     sum += score[i][j];


   }
   printf("学生%d的总分数%d\n：",i+1,sum);

  }  
  for(int i =  0; i<4;i++)
  {
    double sum = 0;
    for(int j =0;j<3;j++)
    {
      sum +=score[j][i];

    }
    printf("平均分:%lf\n",sum/3);
}
    return 0;

}


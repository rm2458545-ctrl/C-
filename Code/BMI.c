#include <stdio.h>
int main()
{
  double kg =0.0;
  double cm =0.0;
  double BMI = kg / cm;
  printf("请输入体重：");
  scanf("%le",&kg);
  printf("请输入身高：");
  scanf("%le",&cm);
  double m = cm / 100.0;
  BMI = kg / (m * m);
  printf("你的BMI指数为：%.2f\n", BMI);

  if(BMI < 18.5)
  {
    printf("偏瘦(注意加强营养)\n");
  }

  else if(BMI>=18.5&&BMI <= 23.9)
  {
    printf("中等（注意保持)\n");
  }
  else if(BMI > 23.9)
  {
    printf("偏胖（注意运动)\n");
  }

  return 0;
}

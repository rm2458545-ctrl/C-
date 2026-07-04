#include <stdio.h>
int main() {
    int peach = 1;  // 第10天剩余桃子
    // 倒推9天
    for(int day = 9; day >= 1; day--)
    {
        peach = (peach + 1) * 2;
    }
    printf("第一天摘的桃子总数：%d\n", peach);
    return 0;
}

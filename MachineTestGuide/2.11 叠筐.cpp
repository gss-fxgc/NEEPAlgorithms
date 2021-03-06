#include <stdio.h>

int main() {
    int outputBuf[82][82]; //用于预排版的输出缓存
    char a, b; //输入的两个字符
    int n; //叠筐大小
    bool firstCase = true; //是否为第一组数据标志，初始值为true
    while (scanf("%d %c %c", &n, &a, &b) == 3) {
        //若是第一组数据
        if (firstCase == true)
            firstCase = false; //将第一组数据标志标记成false
        else
            printf("\n"); //否则输出换行
        //从内到外输出每个圈
        for (int i = 1, j = 1; i <= n; i += 2, j++) {
            //计算每个圈右上角点的坐标
            int x = n / 2 + 1, y = x;
            x -= j - 1;
            y -= j - 1;
            //计算当前圈需要使用哪个字符
            char c = j % 2 == 1 ? a : b;
            //对当前圈进行赋值
            for (int k = 1; k <= i; k++) {
                outputBuf[x + k - 1][y] = c; //左边赋值
                outputBuf[x][y + k - 1] = c; //上边赋值
                outputBuf[x + i - 1][y + k - 1] = c; //右边赋值
                outputBuf[x + k - 1][y + i - 1] = c; //下边赋值
            }
        }
        //n为1时不需要磨角
        if (n != 1) {
            //将四角置为空格
            outputBuf[1][1] = ' ';
            outputBuf[n][1] = ' ';
            outputBuf[1][n] = ' ';
            outputBuf[n][n] = ' ';
        }
        //输出已经经过排版的在输出缓存中的数据
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%c", outputBuf[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

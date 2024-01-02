#include <stdio.h>
#include <math.h>
#define b 1//积分上限
#define a 0//积分下限

double f(double x, double y) //目标函数
{
    return -2*x*y;
}

void output(int i, double ynl, double xnl)  //文件读写函数
{
    FILE*fp;
    fp=fopen("Euler.txt","a+");
    fprintf(fp,"%d      ",i);
    fprintf(fp,"x%d=%lf     ",i,xnl);
    fprintf(fp,"y%d=%lf\n",i,ynl);
}

int main()
{
    int i;
    double y0;
    double xn, yn, xnl, ynl, ynlb;
    double h,n;
    printf("请输入y0的值:");
    scanf("%lf", &y0);
    printf("请输入n来把区间分成n等份(正整数):");
    scanf("%lf", &n);
    //初始化文本文件
    FILE *fp;
    fp=fopen("Euler.txt","w+");
    fprintf(fp,"");
    fclose(fp);
    //改进欧拉法核心
    h = (b - a) / n;
    xn = a;
    yn = y0;
    for (i = 1; i <= n; i++)
    {
        xnl = xn + h;
        ynlb = yn + h * f(xn, yn);
        ynl = yn + h / 2 * (f(xn, yn) + f(xnl, ynlb));
        output(i,ynl,xnl);
        xn = xnl;
        yn = ynl;
    }
    fclose(fp);
    printf("输出文件已放在源代码同目录\n");
    return 0;
}
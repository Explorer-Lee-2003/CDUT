#include <stdio.h>  
#include <math.h>   
#define c 1.0 //积分下限 
#define d 6.0  //积分上限  
  
double f(double x)  //被积函数
{  
    return cos(x);
}  

// 复化梯形法求积分
double Ladder( int n) {
    double h = (d - c) / n; // 计算子区间宽度
    double result = 0.5 * (f(c) + f(d));    // 初始化结果为首尾两点的函数值之和

    for (int i = 1; i < n; i++) {
        double x = c + i * h; // 计算当前子区间的 x 值
        result += f(x); // 累加当前子区间的函数值
    }

    result *= h; // 乘以子区间宽度，得到最终积分结果
    return result;
}

void output(int k, double S2, double S1) //文本读写操作
{
  FILE *fp;
  fp=fopen("Ladder.txt","a+");
  fprintf(fp,"%d",k);
  fprintf(fp,"结果为：%le     ",S2);
  fprintf(fp,"误差：%le\n",S1-S2);
}

void main6()  
{  
    int n;      // 子区间数量
    double eps; // 精度

    // 输入积分子区间数量和精度
    printf("输入子区间数量：");
    scanf("%d", &n);

    printf("输入精度 EPS：");
    scanf("%lf", &eps);
  //初始化文本文件
    FILE *fp;
    fp=fopen("Ladder.txt","w+");
    fprintf(fp,"");                                                                                         
    fclose(fp);

    // 使用复化梯形法计算积分
    double S2, S1 = 0;
    int k = 0;

    do {
        k++;
        S2 = S1;
        S1 = Ladder( n * k * 2);
        // 打印每一次迭代的结果
        output(k,S1,S2);
    } while (fabs(S1 - S2) > eps);
 fclose(fp);
 printf("输出文件已放在源代码同目录\n");
}
    
    
#include <stdio.h>
#define MAX 30          

typedef struct POINT//点的结构，通过结构体能够减少使用数组，使代码更简洁明了，同时减少工作量
{
    double x;   //数组X，也就是矩阵中X的向量
    double y;   //数组Y，也就是矩阵中Y的向量
}Point;



int main()
{
    int m;//输入点的个数
    int i;
    Point points[MAX];//用来存储点
    static double u11,u12,u21,u22,c1,c2;//用来构建法方程组的变量
    double a,b,tmp;
    printf("\n请输入点个数：");
    scanf("%d",&m);
    if(m>MAX)
    {
        return 1;
    }
    if(m<=0)
    {
        return 1;
    }
    printf("\n请输入x点y点的坐标（如(1,0)，请直接输入10，然后按回车再次输入）：\n");
    for(i=0;i<m;i++)
    {
        scanf("%lf%lf",&points[i].x,&points[i].y);
    }
    //列出方程U(a,b)
    for(i=0;i<m;i++)//即解法方程组
    {
        u21+=points[i].x;
        u22+=points[i].x*points[i].x;
        c1+=points[i].y;
        c2+=points[i].x*points[i].y;
    }
    u12=u21;
    u11=m;
    //进行求解
    a=(c1*u22-c2*u12)/(u11*u22-u12*u21);
    b=(c1*u21-c2*u11)/(u21*u12-u22*u11);

    //输出最小二乘解
    printf("\n最小二乘解的线性方程为 :S(x)=%f+%fx   y=%lf\n",a,b);

    return 0;
}
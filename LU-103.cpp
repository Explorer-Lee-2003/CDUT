#include<stdio.h>
#include<math.h>
#define MAX_SIZE 100 /* 矩阵最大维数 */

int Direct( int n, double a[][MAX_SIZE], double b[] )  /*--- 输出直接法的解 ---*/ //copyright(c) 103
{
    int flag = 1;
    double y[n];
    int r;
    int i;
    int k;
    double sum_u, sum_l;
    for(r=1;r<n;r++)
        a[r][0] = a[r][0]/a[0][0];  //初始化矩阵
    for(r=1;r<n;r++)
    {
        for(i=r;i<n;i++)
        {
            sum_u = 0;
            for(k=0;k<r;k++)
                sum_u += a[r][k]*a[k][i];
            a[r][i] = a[r][i]-sum_u;        //计算矩阵U
        }
        for(i=r+1;i<n&&r!=n-1;i++)
        {
            sum_l = 0;
            for(k=0;k<r;k++)
                sum_l += a[i][k]*a[k][r];
            a[i][r] = (a[i][r]-sum_l)/a[r][r];      //计算矩阵L
        }
    }
    for(r=0;r<n;r++)
    {
        if(a[r][r]==0) //判断矩阵的顺序主子式是否为0，只有非奇异矩阵才能LU分解
        {
            flag = 0;
            return flag;
        }
    }
    y[0] = b[0];
    double sum;
    for(i=1;i<n;i++)    //计算矩阵y
    {
        sum = 0;
        for(k=0;k<i;k++)
            sum += a[i][k]*y[k];
        y[i] = b[i]-sum;
    }
    b[n-1] = y[n-1]/a[n-1][n-1];
    for(i=n-2;i>=0;i--)     //计算矩阵x
    {
        sum = 0;
        for(k=i+1;k<n;k++)
            sum += a[i][k]*b[k];
        b[i] = (y[i]-sum)/a[i][i];
    }
    return flag;
}

void main3()
{
    int n, i, j;
    double a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE];
    printf("请输入阶数n\n");
    scanf("%d",&n);
    printf("请输入增广矩阵\n");
        for ( i=0; i<n; i++ )
        {
            for ( j=0; j<n; j++ )
                scanf("%lf", &a[i][j]);
            scanf("%lf", &b[i]);
        }
    if ( Direct(n, a, b) )
    {
        printf("方程组的解为【按x1开始依次输出】\n");
            for ( j=0; j<n; j++ )
                printf("%.8lf\n", b[j]);
    }
    else
        printf("计算错误！\n");
}

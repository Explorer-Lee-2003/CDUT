#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define MaxSize 100
double A[MaxSize][MaxSize];
double B[MaxSize];
double C[MaxSize][MaxSize];
double D[MaxSize][MaxSize];//储存D逆
double E[MaxSize][MaxSize];//储存-(D-1)*(L+U)
double F[MaxSize];//(D-1)*B
double X[MaxSize];
double X1[MaxSize];
double Y[MaxSize];
int n;//矩阵尺寸大小
float EPS;//精度

//初始化矩阵
void InitMatrix()
{
    int i,j;
    for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     {
        if(i==j)
        {
            D[i][j]=1/A[i][i];
            E[i][j]=0;
        }
        if(i<j)
            E[i][j]=A[i][j];
        if(i>j)
            E[i][j]=A[i][j];
     }
}

//矩阵运算 copyright(c) 103
void Jacobi()
{
    int i,j,k,r;
    double sum1,sum2,sum4=0;
    for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     {
        sum1=0;
       for(k=0;k<n;k++)          
       {
        sum1=sum1+D[i][k]*E[k][j];
       }
       E[i][j]=-sum1;           //(D-1)*(L+U)
     }
     //求E的谱半径，判断是否收敛
     //E的谱半径>1,不一定发散;但是E的谱半径<1,一定收敛
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
         sum4=sum4+pow(E[i][j],2);
     if(sqrt(sum4)<1)
        printf("B矩阵谱半径<1，必有数值解！\n");
     else
     printf("B矩阵谱半径>1，不一定有数值解！\n");
     
     for(i=0;i<n;i++)
      {
          sum2=0;
          for(k=0;k<n;k++)
          {
              sum2=sum2+D[i][k]*B[k];
          }
          F[i]=sum2;            //(D-1)*B
      }
    //X迭代
    for(r=1;r<100;r++)
    {
        int flag=0;
        double sum3;
        for(i=0;i<n;i++)
            X1[i]=X[i];
        for(i=0;i<n;i++)
        {
        sum3=0;
        for(k=0;k<n;k++)
        {
         sum3=sum3+E[i][k]*X1[k];
        }
        X[i]=F[i]+sum3;
        }
      for(j=0;j<n;j++)
          if(fabs(X[j]-X1[j])<EPS)
            flag++;
     if(flag==n)
     {
        printf("迭代第%d次满足精度！\n",r);
        break;
     }
    
    }

}


//赋值输入部分
void input()
{
    int i,j;
    printf("请输入系数矩阵A：\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%lf",&A[i][j]);
    printf("请输入向量B：\n");
    for(i=0;i<n;i++)
        scanf("%lf",&B[i]);
    X[MaxSize]={0};                 //雅可比迭代初始向量给定为X=[0,0,0]^T
}

//数据输出
void print()
{
  int i,j;
  printf("方程组的近似解：\n");
  for(i=0;i<n;i++)
    printf("%lf\n",X[i]);
}



int main()
{
    void InitMatrix();
    void Jacobi();
    void input();
    void print();
    printf("请输入矩阵行数：\n");
    scanf("%d",&n);
    printf("请输入精度EPS\n");
    scanf("%e",&EPS);
    input();
    InitMatrix();
    Jacobi();
    print();
    return 0;
}


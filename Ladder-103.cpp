#include <stdio.h>  
#include <math.h>   
#define c 1.0 //积分下限 
#define d 6.0  //积分上限  
  
double f(double x)  //被积函数
{  
    return cos(x);
}  

void output(double T2, double T1) //文本读写操作
{
  FILE *fp;
  fp=fopen("Ladder.txt","a+");
  fprintf(fp,"结果为：%le     ",T2);
  fprintf(fp,"误差：%le\n",T2-T1);
}

void main6()  
{  
  int k,i; 
  double eps;  
  int n;  //区间划分数
  double T1=0,T2=0,s,x=0;
  double h;//积分步长
  printf("请输入精度eps：\n");
  scanf("%le",&eps);
  printf("请输入k的最大值(大于等于0的整数):\n");
  scanf("%d",&k);
  //初始化文本文件
  FILE *fp;
  fp=fopen("Ladder.txt","w+");
  fprintf(fp,"");
  fclose(fp);
  //复化梯形求积核心
 for(i=0;i<=k;i++)
 {
   n=pow(2,i);  //pow()求幂运算函数
   h=(d-c)/n;
   T1=((f(c)+f(d))*h)/2;
    do
    {  
      s=0;
      x=c+k*h+h/2;
      s=s+f(x);
      T2=(T1+h*s)/2;
      n=n*2;
        if(fabs(T1-T2)<eps)
        {
          break;
        }
      h=h/2;
      T1=T2;
    }
    while (1);
   output(T2,T1);
 }
 fclose(fp);
 printf("输出文件已放在源代码同目录\n");
}
    
    
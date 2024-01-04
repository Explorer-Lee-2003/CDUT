#include<stdio.h>
#include<math.h>
#define	N 100

float f(float x)		//定义f(x)
{
	return x * x * x + x * x - 3 * x - 3;
}

float df(float x)		//定义df(x)/x
{
	return 3 * x * x + 2 * x - 3;
}

float newton(float x0,float eps)		//牛顿迭代法主算法 copyright(c) 103
{
	float x1 = 0,d = 0;
	int k = 0;
	if (df(x0) == 0)
	{
		printf("失败\n");
	}
	else
	{
		do
		{
			x1 = x0 - f(x0) / df(x0);
			if (k++ > N || fabs(df(x1)) < eps)
			{
				printf("失败\n");
				break;
			}
			d = fabs(x1) < 1 ? x1 - x0 : (x1 - x0) / x1;
			x0 = x1;
			printf("x(%d)=%f\n", k, x0);
		} while (fabs(d) > eps);
	}
	return x1;
}

void main1()
{
	float x0, y0, eps;
	printf("输入x0\n");
	scanf("%f", &x0);
	printf("输入eps\n");
	scanf("%e", &eps);
	y0 = newton(x0,eps);
	printf("方程根%f\n", y0);
}
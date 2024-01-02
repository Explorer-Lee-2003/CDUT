#include<stdio.h>
# define N 100	
int main()		//copyright(c) 103
{
    //设置数据; 
	int n,i,j;double l[N],l1[N],l2[N],x,y=0 ,x1[N],y1[N];
	printf("输入已知数据对数："); 
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{  
		//先输入一个x，再输入一个y 
        printf("输入X%d\n",i+1);
		scanf("%lf",&x1[i]);
        for(j=i;j<n;j++)
		{
            printf("请输入Y%d\n",j+1);
            scanf("%lf",&y1[i]);
            break;
        }
		//将数据进行赋初值 
		l1[i]=1;
		l2[i]=1;
	}
	printf("输入最后已知的x，求y：") ;//输入数据对
	scanf("%lf",&x);
	//进行l(x)的分子分母构造 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			l1[i]=1.0*l1[i]*(x-x1[j]);//分子构造
			if(i!=j)
			  {
			   l2[i]=1.0*l2[i]*(x1[i]-x1[j]);//分母构造
			  }
		}
		l1[i]=1.0*l1[i]/(x-x1[i]);
		l[i]=1.0*l1[i]/l2[i];	
    }
    //计算得到y; 
    for(i=0;i<n;i++)
    {
    	y=y+l[i]*y1[i];
	}
	printf("%lf",y);
	return 0;
}
#include <stdio.h>
#include <windows.h>        //SetConsoleOutputCP(65001)依赖的头文件
#include "newton-103.cpp"
#include "Jacobi-103.cpp"
#include "LU-103.cpp"
#include "Least_squares_linear_fit-103.cpp"
#include "Lagrange_interpolation-103.cpp"
#include "Ladder-103.cpp"
#include "Euler-103.cpp"            //引用其他cpp文件，""表示在main.cpp同目录下寻找头文件

int main()
{
    SetConsoleOutputCP(65001);      //为什么要引入此代码？在vscode中，中文默认是按照UTF-8编码的，而Windows控制台中文默认按照GB18030编码，这会导致单独打开
                                    //main.cpp时中文乱码，而在vscode中调试却没有问题。此代码可以强制将Windows控制台中文编码转化为UTF-8，解决中文乱码问题
    int your_num;
    printf("1.牛顿迭代法\n2.雅可比迭代法\n3.LU直接分解法\n4.线性最小二乘拟合\n5.拉格朗日插值法\n6.复化梯形求积\n7.改进欧拉法\n请输入对应的数字\n");
    scanf("%d",&your_num);
    float x0,y0,eps;
    switch (your_num)
    {
    case 1: main1();break;
    case 2: main2();break;
    case 3: main3();break;
    case 4: main4();break;
    case 5: main5();break;
    case 6: main6();break;
    case 7: main7();break;
    default: break;
    }
    return 0;
}
#include <stdio.h>
#include <math.h>
#define MAX_ 100

// 计算向量的二范数
double Cal(double T[MAX_], int n) {
    double s = 0.0;
    for (int i = 0; i < n; i++) {
        s += T[i] * T[i];
    }
    return sqrt(s);
}

// 雅可比迭代法
void Jacobi(double R[MAX_][MAX_], double C[MAX_], double S[MAX_], int n, double eps, int m)
 {
    int k = 0;
    double t[MAX_];

    while (k < m) {
        // 对每个方程进行迭代计算
        for (int i = 0; i < n; i++) {
            t[i] = C[i];

            // 计算新的解
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    t[i] -= R[i][j] * S[j];
                }
            }

            t[i] /= R[i][i];
        }
        double error = Cal(t, n);// 计算误差
        // 如果误差小于精确度，表示收敛
        if (error < eps) {
            printf("在 %d 次后收敛\n", k);
            return;
        }
        for (int i = 0; i < n; i++)
         {                                      // 解向量
            S[i] = t[i];
        }

        k++;
    }
}

int main2() {
    int n;
    double R[MAX_][MAX_], C[MAX_], S[MAX_];
    double eps;
    int m;
    printf("输入阶数(1-%d): ", MAX_);
    scanf_s("%d", &n); 
    printf("输入系数矩阵【输一个按一次回车】:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%lf", &R[i][j]);
        }
    }
    printf("输入矩阵的最后一列:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf_s("%lf", &C[i]);
    }
    printf("输入精确度: ");
    scanf_s("%lf", &eps);

    printf("允许最大迭代次数: ");
    scanf_s("%d", &m);

    // 初始化解向量
    for (int i = 0; i < n; i++) {
        S[i] = 0.0;
    }

    // 雅可比迭代法
    Jacobi(R, C, S, n, eps, m);

    printf("\n方程组解为:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, S[i]);
    }

    return 0;
}

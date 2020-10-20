#include <stdio.h>
#include <stdlib.h>

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1000;
const double wucha = 1e-6;  //误差
const int MAX_count = 500;

double A[N][N];
double b[N];
double curx[N];
double lastx[N];
int n, cnt;
double W;

void init() {
    printf("输入未知数个数：");
    cin >> n;
    printf("输入方程组矩阵A：\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }
    printf("输入b向量：\n");
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    cout << endl;
}

void init_x() {
    cout << "请对x赋初值：" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> curx[i];
    }
}

bool judge() {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (curx[i] - lastx[i]) * (curx[i] - lastx[i]);
    }
    sum = sqrt(sum);
    if (sum <= wucha)
        return 1;
    else
        return 0;
}

void output() {
    cout << "迭代次数为：" << cnt << endl;
    cout << "近似解为：";
    for (int i = 1; i <= n; i++) {
        cout << fixed << setprecision(15) << curx[i] << " ";
    }
    cout << endl << endl;
}

void Jacobi() {  // x初值都设置为0
    cout << "雅可比迭代法：" << endl;
    init_x();
    int flag = 0;
    double sum;
    for (int k = 1; k < MAX_count; k++) {
        for (int i = 1; i <= n; i++) {
            lastx[i] = curx[i];
        }

        for (int i = 1; i <= n; i++) {
            sum = 0;
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                sum += A[i][j] * lastx[j];
            }
            curx[i] = (b[i] - sum) / A[i][i];
        }
        if (judge()) {
            flag = 1;
            cnt = k;
            output();
            break;
        }
    }
    if (flag == 0) cout << "error！" << endl << endl;
}

void gauss_seidel() {
    cout << "高斯—赛德尔迭代法：" << endl;
    init_x();
    int flag = 0;
    double sum;
    double t;
    for (int k = 1; k < MAX_count; k++) {
        double e = 0;
        for (int i = 1; i <= n; i++) {
            t = curx[i];
            sum = 0;
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                sum += A[i][j] * curx[j];
            }
            curx[i] = (b[i] - sum) / A[i][i];
            if (fabs(curx[i] - t) <= e) {
            } else {
                e = fabs(curx[i] - t);
            }
        }
        if (e < wucha) {
            flag = 1;
            cnt = k;
            output();
            break;
        }
    }
    if (flag == 0) cout << "error！" << endl << endl;
}

int main() {
    init();
    Jacobi();
    gauss_seidel();
    return 0;
}
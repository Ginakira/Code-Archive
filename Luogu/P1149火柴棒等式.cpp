/*************************************************************************
	> File Name: P1149火柴棒等式.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月22日 星期五 16时40分24秒
 ************************************************************************/

#include<iostream>
using namespace std;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int cal(int n) {
    int i, k = 0;
    for (i = n; i != 0; i /= 10) k += num[i % 10];
    if (n == 0) k += num[0];
    return k;
}

int main() {
    int n, i , j, ans = 0;
    cin >> n;
    for (i = 0; i <= 1200; ++i) {
        for (j = 0; j <= 1200; ++j) {
            if (cal(i) + cal(j) + cal(i + j) + 4 == n)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

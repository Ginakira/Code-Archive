/*************************************************************************
	> File Name: P1579哥德巴赫猜想升级版.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月08日 星期一 19时23分46秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
bool is_prime(int a) {
    for(int i = 2; i <= sqrt(a); ++i) {
        if(a % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for(int i = 2; i < n - 6; i++) {
        for(int j = 2; j < n - 2 - i; j++) {
            int k = n - i - j;
            if(is_prime(i) && is_prime(j) && is_prime(k)) {
                cout << i << ' ' << j << ' ' << k << endl;
                return 0;
            }
        }
    }
    return 0;
}

/*************************************************************************
	> File Name: P1217回文质数.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月04日 星期四 23时12分48秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int huiwen[10000000];
bool is_prime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n = 3;
    int d1, d2, d3, d4;
    huiwen[0] = 5; huiwen[1] = 7; huiwen[2] = 11;
    //三位回文数
    for(d1 = 1; d1 <= 9; d1 += 2) {
        for(d2 = 0; d2 <= 9; d2++) {
            huiwen[n] = d1 * 100 + d2 * 10 + d1;
            n++;
        }
    }

    //四位回文数
    for(d1 = 1; d1 <= 9; d1 += 2) {
        for(d2 = 0; d2 <= 9; d2++) {
            huiwen[n] = d1 * 1000 + d2 * 100 + d2 * 10 + d1;
            n++;
        }
    }

    //五位回文数
    for(d1 = 1; d1 <= 9; d1 += 2) {
        for(d2 = 0; d2 <= 9; d2++) {
            for(d3 = 0; d3 <= 9; d3++) {
                huiwen[n] = d1 * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1;
                n++;
            }
        }
    }

    //六位回文数
    for(d1 = 1; d1 <= 9; d1 += 2) {
        for(d2 = 0; d2 <= 9; d2++) {
            for(d3 = 0; d3 <= 9; d3++) {
                huiwen[n] = d1 * 100000 + d2 * 10000 + d3 * 1000 + d3 * 100 + d2 * 10 + d1;
                n++;
            }
        }
    }

    //七位回文数
    for(d1 = 1; d1 <= 9; d1 += 2) {
        for(d2 = 0; d2 <= 9; d2++) {
            for(d3 = 0; d3 <= 9; d3++) {
                for (d4 = 0; d4 <= 9; d4++) {
                    huiwen[n] = d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
                    n++;
                }
            }
        }
    }

    //八位回文数
    for(d1 = 1; d1 <= 9; d1 += 2) {
        for(d2 = 0; d2 <= 9; d2++) {
            for(d3 = 0; d3 <= 9; d3++) {
                for(d4 = 0; d4 <= 9; d4++) {
                    huiwen[n] = d1 * 10000000 + d2 * 1000000 + d3 * 100000 + d4 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
                    n++;
                }
            }
        }
    }
    int a, b;
    cin >> a >> b;
    for (int i = 0; huiwen[i] != '\0'; ++i) {
        if(huiwen[i] < a) continue;
        if(huiwen[i] > b) break;
        if(is_prime(huiwen[i])) cout << huiwen[i] << endl;
    }
    return 0;
}

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, tmp, tn;
    double ave, sum = 0;
    cin >> n;
    tn = n;
    while (tn--) {
        cin >> tmp;
        sum += tmp;
    }
    ave = sum / n;
    printf("%.2f", ave);
    return 0;
}
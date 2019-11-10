/*************************************************************************
	> File Name: P1036选数.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月01日 星期一 19时46分15秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int num[30];
bool is_prime(int n) {
    int s = sqrt(double(n));
    for(int i = 2; i <= s; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int dfs(int left, int already_sum, int start, int end) {
    if (left == 0) return is_prime(already_sum);
    int sum = 0;
    for(int i = start; i <= end; ++i) {
        sum += dfs(left - 1, already_sum + num[i], i + 1, end);
    }
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> num[i];
    cout << dfs(k, 0, 0, n - 1) << endl;
    return 0;
}

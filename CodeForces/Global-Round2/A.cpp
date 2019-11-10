/*************************************************************************
	> File Name: A.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月06日 星期六 19时39分25秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int c[300001];

int main() {
    int n, ans1, ans2;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for(int i = n - 1; i >= 0; --i) {
        if(c[0] != c[i]) {
            ans1 = i;
            break;
        }
    }
    for(int j = 0; j <= n - 1; ++j) {
        if(c[n - 1] != c[j]) {
            ans2 = n - 1 - j;
            break;
        }
    }
    cout << max(ans1, ans2) << endl;
    return 0;
}

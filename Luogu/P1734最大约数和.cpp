#include <iostream>
#include <algorithm>
using namespace std;

int sum[1010];
int dp[1010];

int cal(int n) {
    if(n == 1) return 1;
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        if(n % i == 0) ans += i;
    }
    return ans;
}

bool cmp(int a, int b) {return a > b;}

int main() {
    int s;
    cin >> s;
    for(int i = 1; i < s; ++i) {
        sum[i] = cal(i);
        cout << "#" << sum[i] << endl;
    }
        
    return 0;
}
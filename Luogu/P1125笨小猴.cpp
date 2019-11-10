#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


bool isprime(int a) {
    if(a == 0 || a == 1) return false;
    if(a == 2) return true;
    for(int i = 2; i * i <= a; ++i) {
        if(a % i == 0) return false;
    }
    return true;
}


int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int maxn = 0, minn = 1000;
    int cnt = 1;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] != s[i + 1]) {
            maxn = max(maxn, cnt);
            minn = min(minn, cnt);
            cnt = 1;
        }
        else cnt++;
    }
    if(isprime(maxn - minn)) cout << "Lucky Word\n" << maxn - minn << endl;
    else cout << "No Answer\n0\n";
    return 0;
}
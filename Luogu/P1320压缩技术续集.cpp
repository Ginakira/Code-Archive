#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ans[10000];
int main() {
    int n = 0, cnt = 0;
    char a, b = '0';
    while(cin >> a) {
        ++n;
        if(a == b) ans[cnt]++;
        else {
            ans[++cnt]++;
            b = a;
        }
    }
    cout << sqrt(n);
    for(int i = 0; i <= cnt; ++i) {
        cout << ' ' << ans[i];
    }
    return 0;
}
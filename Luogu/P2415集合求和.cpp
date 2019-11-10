#include <iostream>
#include <cmath>
using namespace std;
long long ans = 0;
int num[31], n = 0;
int main() {
    while(cin >> num[n++]);
    for(int i = 0; i < n - 1; ++i) {
        ans += num[i];
    }
    ans *= pow(2, n - 2);
    cout << ans << endl;
    return 0;
}
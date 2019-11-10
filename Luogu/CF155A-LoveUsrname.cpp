#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, tmp, maxa = 0, mina = INT_MAX, ans = 0;
    cin >> n;
    cin >> tmp;
    maxa = tmp, mina = tmp;
    for(int i = 1; i < n; ++i) {
        cin >> tmp;
        if(tmp < mina || tmp > maxa) ans++;
        mina = min(mina, tmp);
        maxa = max(maxa, tmp);
    }
    cout << ans << endl;
    return 0;
}
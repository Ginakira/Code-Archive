#include <iostream>
using namespace std;

int main() {
    long long k, l, cal, ans;
    cin >> k >> l;
    if(l == 1) {
        cout << "YES\n-1";
        return 0;
    }
    long long tmp = 1;
    for(ans = 1; ans; ++ans) {
        tmp *= k;
        //cout << tmp << ' ' << ans << endl;
        if(tmp == l) {
            cout << "YES\n" << ans - 1;
            return 0;
        }
        else if(tmp > l) {
            cout << "NO";
            return 0;
        }
    }
    return 0;
}
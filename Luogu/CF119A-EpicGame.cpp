#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, n, cnt = 1, gets, geta;
    cin >> a >> b >> n;
    while(true) {
        gets = __gcd(n, a);
        geta = __gcd(n, b);
        if(cnt % 2 != 0) {
            if(gets > n) break;
            n -= gets;
        }
        else {
            if(geta > n) break;
            n -= geta;
        }
        cnt++;
    }
    //cout << cnt << endl;
    if(cnt % 2 == 0) cout << 0;
    else cout << 1;
    return 0;
}
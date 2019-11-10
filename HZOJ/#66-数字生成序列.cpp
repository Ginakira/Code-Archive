#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    long long ans, maxl = -1;
    for (long long i = 1; i < 1000000; ++i) {
        long long cnt = 0, tmp = i;
        while(tmp != 1) {
            if (tmp % 2 == 0) tmp /= 2;
            else
                tmp = 3 * tmp + 1;
            cnt++;
        }
        if(cnt > maxl) {
            maxl = cnt;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <climits>
using namespace std;

int a[233];

int main() {
    int n, l, s = 0, maxs = 0, maxn = 0;
    cin >> n >> l;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        maxn = max(a[i], maxn);
    }
    for(int i = l; i <= maxn; ++i) {
        s = 0;
        for(int j = 0; j < n; ++j) s += a[j] / i * i;
        maxs = max(s, maxs);
    }
    std::cout << maxs;
    return 0;
}
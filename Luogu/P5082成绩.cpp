#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long n, tmp;
    scanf("%lld", &n);
    long long line = 0, real = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &tmp);
        line += tmp;
    }
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &tmp);
        real += tmp;
    }
    double ans = (line * 3 - real * 2) / double(line - real);
    printf("%.6f\n", ans);
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    long long h1, m1, s1, h2, m2, s2, n;
    scanf("%lld:%lld:%lld", &h1, &m1, &s1);
    scanf("%lld:%lld:%lld", &h2, &m2, &s2);
    cin >> n;
    cout << ((h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1)) * n;
    return 0;
}
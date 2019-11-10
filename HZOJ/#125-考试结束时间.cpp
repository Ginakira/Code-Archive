#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int t, h, m, s, th;
    bool early = false;
    scanf("%d%d%d%d", &h, &m, &s, &t);
    double per = 100.0 * t / 86400.0;
    h += t / 3600;
    t %= 3600;
    m += t / 60;
    t %= 60;
    s += t;
    if (s > 59) m++, s %= 60;
    if (m > 59) h++, m %= 60;
    if (h > 23) h %= 24;
    if(h == 0) {
        early = true;
        th = 12;
    }
    else th = h > 12 ? h - 12 : h;
    printf("%d:%d:%d", th, m, s);
    if (h < 12 || early)
        printf("am\n");
    else
        printf("pm\n");
    printf("%.2f%%", per);
    return 0;
}
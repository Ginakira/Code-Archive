#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int num, h, m, s, th;
    scanf("%d", &num);
    h = num / 3600;
    num %= 3600;
    m = num / 60;
    num %= 60;
    s = num;
    th = h > 12 ? h - 12 : h;
    printf("%02d:%02d:%02d ", th, m, s);
    if (h < 12)
        printf("am");
    else if (h == 12)
        printf("midnoon");
    else
        printf("pm");
    return 0;
}
#include <stdio.h>
int leapyear(int y) {
    if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0) {
        return 1;
    }
    return 0;
}
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    if (leapyear(y) == 1) day[2] = 29;
    if (m > 0 && m <= 12 && d > 0 && d <= day[m]) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
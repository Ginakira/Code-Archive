#include <stdio.h>
#define MAXN 1000000

int mark[MAXN + 5];

int main() {
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        if (temp > 0) mark[temp] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (mark[i] != 0) continue;
        printf("%d\n", i);
        return 0;
    }
    return 0;
}
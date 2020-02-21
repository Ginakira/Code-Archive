#include <stdio.h>
#include <stdlib.h>
#define MAXN 500

int main() {
    int n, arr[MAXN + 5];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    int target;
    scanf("%d", &target);
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (arr[i] + arr[j] == target) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    return 0;
}
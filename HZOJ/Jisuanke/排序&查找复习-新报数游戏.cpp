#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000

#define swap(a, b)                \
    {                             \
        __typeof(a) __temp = (a); \
        (a) = (b);                \
        (b) = __temp;             \
    }

void quick_sort(int *arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = arr[(l + r) >> 1];
        do {
            while (x <= y && arr[x] < z) ++x;
            while (x <= y && arr[y] > z) --y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort(arr, x, r);
        r = y;
    }
    return;
}

int binary_search(int *arr, int n, int tar) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (arr[mid] <= tar)
            head = mid;
        else
            tail = mid - 1;
    }
    return head;
}

int main() {
    int n, m, arr[MAXN + 5], tar;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &tar);
        int ind = binary_search(arr, n, tar);
        if (ind == -1) ind = 0;
        i &&printf(" ");
        printf("%d", arr[ind]);
    }
    return 0;
}
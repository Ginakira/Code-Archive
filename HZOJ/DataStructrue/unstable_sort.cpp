#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define swap(a, b)                \
    {                             \
        __typeof(a) __temp = (a); \
        (a) = (b);                \
        (b) = __temp;             \
    }

#define TEST(arr, n, func, args...)                \
    {                                              \
        int *num = (int *)malloc(sizeof(int) * n); \
        memcpy(num, arr, sizeof(int) * n);         \
        output(num, n);                            \
        printf("%s = ", #func);                    \
        func(args);                                \
        output(num, n);                            \
        free(num);                                 \
    }

void select_sort(int *num, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int ind = i;
        for (int j = i + 1; j < n; ++j) {
            if (num[ind] > num[j]) ind = j;
        }
        swap(num[i], num[ind]);
    }
    return;
}

void quick_sort(int *num, int l, int r) {
    if (r < l) return;
    int x = l, y = r, z = num[l];  // z为选择的基准值
    while (x < y) {
        while (x < y && num[y] >= z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return;
}

// 优化 稳定在O(nlogn)
void quick_sort_optimized(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (x <= y && num[x] < z) ++x;
            while (x <= y && num[y] > z) --y;
            if (x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort_optimized(num, x, r);
        r = y;
    }
    return;
}

void randint(int *arr, int n) {
    while (n--) arr[n] = rand() % 100;
    return;
}

void output(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; ++i) {
        i &&printf(" ");
        printf("%d", arr[i]);
    }
    printf("]\n");
    return;
}

int main() {
#define max_op 20
    srand(time(0));
    int arr[max_op];
    randint(arr, max_op);
    TEST(arr, max_op, select_sort, num, max_op);
    TEST(arr, max_op, quick_sort_optimized, num, 0, max_op - 1);
    return 0;
}
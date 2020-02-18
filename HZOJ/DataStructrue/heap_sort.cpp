#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b)              \
    {                           \
        __typeof(a) __temp = a; \
        a = b;                  \
        b = __temp;             \
    }

//自上向下调整
void down_update(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return;
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i >= 1; --i) {
        down_update(arr, n, i);
    }
    for (int i = n; i > 1; --i) {
        swap(arr[i], arr[1]);
        down_update(arr, i - 1, 1);
    }
    return;
}

void output(int *arr, int n) {
    printf("Arr[%d] = [", n);
    for (int i = 0; i < n; ++i) {
        printf(" %d", arr[i]);
    }
    printf("]\n");
    return;
}

int main() {
#define max_op 20
    srand(time(0));
    int *arr = (int *)malloc(sizeof(int) * max_op);
    for (int i = 0; i < max_op; ++i) {
        int val = rand() % 100;
        arr[i] = val;
    }
    output(arr, max_op);
    heap_sort(arr, max_op);
    output(arr, max_op);
    free(arr);
    return 0;
}
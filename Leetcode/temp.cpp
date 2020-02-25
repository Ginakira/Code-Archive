#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define swap(a, b)              \
    {                           \
        __typeof(a) __temp = a; \
        a = b;                  \
        b = __temp;             \
    }

void downupdate(double *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[ind], arr[temp]);
        ind = temp;
    }
    return;
}

void head_sort(double *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i >= 1; i--) {
        downupdate(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);
        downupdate(arr, i - 1, 1);
    }
    return;
}

double operate(double a, double b) { return pow(a * b * b * 1.0, 1.0 / 3.0); }

void output(double *arr, int n) {
    double ans = 0;
    int i;
    for (i = n - 1; i > 0; i--) {
        arr[i - 1] = operate(arr[i], arr[i - 1]);
        head_sort(arr, i);
    }
    if (i == 0) ans = arr[0];
    printf("%lf\n", ans);
    return;
}

int main() {
    int n, m;
    double arr[1005];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        arr[i] = m;
    }
    head_sort(arr, n);
    output(arr, n);
    return 0;
}
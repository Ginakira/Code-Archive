#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define swap(a, b)                \
    {                             \
        __typeof(a) __temp = (a); \
        (a) = (b);                \
        (b) = __temp;             \
    }

typedef struct Heap {
    double *data;
    int cnt, size;
} Heap;

void init(Heap *h, int n) {
    if (!h) return;
    h->data = (double *)malloc(sizeof(double) * (n + 1));
    h->cnt = 0;
    h->size = n;
    return;
}

double top(Heap *h) { return h->data[1]; }

int empty(Heap *h) { return h->cnt == 0; }

int push(Heap *h, double val) {
    if (!h) return 0;
    if (h->cnt == h->size) return 0;
    h->data[++h->cnt] = val;
    int current = h->cnt, father = current >> 1;
    while (father && h->data[current] > h->data[father]) {
        swap(h->data[current], h->data[father]);
        current = father;
        father = current >> 1;
    }
    return 1;
}

int pop(Heap *h) {
    if (!h) return 0;
    if (empty(h)) return 0;
    h->data[1] = h->data[h->cnt--];
    int ind = 1;
    while ((ind << 1) <= h->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (h->data[l] > h->data[temp]) temp = l;
        if (r <= h->cnt && h->data[r] > h->data[temp]) temp = r;
        if (temp == ind) break;
        swap(h->data[temp], h->data[ind]);
        ind = temp;
    }
    return 1;
}

void clear(Heap *h) {
    if (!h) return;
    free(h->data);
    free(h);
    return;
}

int main() {
    int n, tmp;
    Heap *h = (Heap *)malloc(sizeof(Heap));
    init(h, 1005);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        push(h, tmp);
    }
    for (int i = 1; i < n; ++i) {
        double a = top(h);
        pop(h);
        double b = top(h);
        pop(h);
        tmp = push(h, pow(a, 1.0 / 3.0) * pow(b, 2.0 / 3.0));
    }
    printf("%lf", top(h));
    clear(h);
    return 0;
}
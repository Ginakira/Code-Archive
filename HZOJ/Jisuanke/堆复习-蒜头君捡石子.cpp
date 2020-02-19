#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000
#define swap(a, b)                \
    {                             \
        __typeof(a) __temp = (a); \
        (a) = (b);                \
        (b) = __temp;             \
    }

typedef long long LL;

typedef struct Node {
    LL dis, add;
} Node;

typedef struct Heap {
    Node *data;
    int size, cnt;
} Heap;

int cmp(Node a, Node b) {
    if (a.dis == b.dis) return a.add < b.add;
    return a.dis < b.dis;
}

void init_heap(Heap *h, int n) {
    if (!h) return;
    h->data = (Node *)malloc(sizeof(Node) * (n + 1));
    h->size = n, h->cnt = 0;
    return;
}

int empty(Heap *h) { return h->cnt == 0; }

Node top(Heap *h) { return h->data[1]; }

void update(Heap *h, int ind, int n) {
    while ((ind << 1) <= n) {
        int cur_min = ind, l = ind << 1, r = ind << 1 | 1;
        if (cmp(h->data[l], h->data[cur_min])) cur_min = l;
        if (r <= n && cmp(h->data[r], h->data[cur_min])) cur_min = r;
        if (ind == cur_min) break;
        swap(h->data[cur_min], h->data[ind]);
        ind = cur_min;
    }
    return;
}

int push(Heap *h, Node val) {
    if (!h || h->size == h->cnt) return 0;
    h->data[++h->cnt] = val;
    int ind = h->cnt;
    while (ind >> 1 && cmp(h->data[ind], h->data[ind >> 1])) {
        swap(h->data[ind], h->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(Heap *h) {
    if (!h || empty(h)) return 0;
    h->data[1] = h->data[h->cnt--];
    update(h, 1, h->cnt);
    return 1;
}

void clear_heap(Heap *h) {
    if (!h) return;
    free(h->data);
    free(h);
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        Heap *h = (Heap *)malloc(sizeof(Heap));
        init_heap(h, n + 5);
        Node stone;
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld", &stone.dis, &stone.add);
            push(h, stone);
        }
        LL cnt = 0, walk_dis = 0;
        while (!empty(h)) {
            stone = top(h);
            pop(h);
            cnt++;
            // printf("ID-%lld top%lld-%lld", cnt, stone.dis, stone.add);
            walk_dis = stone.dis;
            if (cnt % 2 == 0) continue;
            stone.dis += stone.add;
            push(h, stone);
            // printf(" WALKING %lld\n", walk_dis);
        }
        printf("%lld\n", walk_dis);
        clear_heap(h);
    }
    return 0;
}
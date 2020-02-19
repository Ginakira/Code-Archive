#include <stdio.h>
#include <stdlib.h>
#define MAXN 50000
#define swap(a, b)                \
    {                             \
        __typeof(a) __temp = (a); \
        (a) = (b);                \
        (b) = __temp;             \
    }

typedef struct Node {
    int id, dis;
} Node;

typedef struct Heap {
    Node *data;
    int size, cnt;
} Heap;

int cmp(Node a, Node b) {
    if (a.dis == b.dis) return a.id < b.id;
    return a.dis > b.dis;
}

void init_heap(Heap *h, int n) {
    h->data = (Node *)malloc(sizeof(Node) * n + 1);
    h->size = n, h->cnt = 0;
    return;
}

Node top_heap(Heap *h) { return h->data[1]; }

int empty_heap(Heap *h) { return h->cnt == 0; }

int push_heap(Heap *h, Node val) {
    if (!h || h->cnt == h->size) return 0;
    h->data[++h->cnt] = val;
    int ind = h->cnt;
    while (ind >> 1 && cmp(h->data[ind], h->data[ind >> 1])) {
        swap(h->data[ind], h->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

void update_heap(Heap *h, int i, int n) {
    while ((i << 1) <= n) {
        int m = i, l = i << 1, r = i << 1 | 1;
        if (cmp(h->data[l], h->data[m])) m = l;
        if (r <= n && cmp(h->data[r], h->data[m])) m = r;
        if (m == i) break;
        swap(h->data[m], h->data[i]);
        i = m;
    }
    return;
}

int pop_heap(Heap *h) {
    if (!h || empty_heap(h)) return 0;
    h->data[1] = h->data[h->cnt--];
    update_heap(h, 1, h->cnt);
    return 1;
}

void clear_heap(Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    Heap *h[101];
    for (int i = 1; i <= 100; ++i) {
        h[i] = (Heap *)malloc(sizeof(Heap));
        init_heap(h[i], MAXN);
    }
    while (T--) {
        int n, spd;
        scanf("%d", &n);
        Node zombie;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &zombie.dis, &spd);
            zombie.id = i;
            push_heap(h[spd], zombie);
        }
        printf("Case #%d:\n", ++kase);
        //开始消灭n次 下标代表速度
        for (int i = 0; i < n; ++i) {
            int cur_max = -1;
            Node zombie1, zombie2;
            for (int j = 1; j <= 100; ++j) {
                if (empty_heap(h[j])) continue;
                //找到的第一个作为当前最大值
                if (cur_max == -1) {
                    cur_max = j;
                    continue;
                }
                //更新&找到当前最远的
                zombie1 = top_heap(h[cur_max]);
                zombie2 = top_heap(h[j]);
                //计算第i秒的距离
                zombie1.dis += i * cur_max;
                zombie2.dis += i * j;
                if (cmp(zombie2, zombie1)) cur_max = j;
            }
            i &&printf(" ");
            printf("%d", top_heap(h[cur_max]).id);
            pop_heap(h[cur_max]);
        }
        printf("\n");
    }
    for (int i = 1; i <= 100; ++i) {
        clear_heap(h[i]);
    }
    return 0;
}
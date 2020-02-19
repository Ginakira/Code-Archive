#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize(2)
#define swap(a, b)                \
    {                             \
        __typeof(a) __temp = (a); \
        (a) = (b);                \
        (b) = __temp;             \
    }

typedef struct Zombie {
    int id, now_dis, speed;
} Zombie;

typedef struct Heap {
    Zombie **data;
    int size, cnt;
} Heap;

int cmp(Zombie *a, Zombie *b) {
    if (a->now_dis == b->now_dis) return a->id < b->id;
    return a->now_dis > b->now_dis;
}

Zombie *get_new_zombie(int id, int now_dis, int speed) {
    Zombie *z = (Zombie *)malloc(sizeof(Zombie));
    z->id = id, z->now_dis = now_dis, z->speed = speed;
    return z;
}

void init_heap(Heap *h, int n) {
    if (!h) return;
    h->data = (Zombie **)malloc(sizeof(Zombie *) * (n + 1));
    h->size = n, h->cnt = 0;
    return;
}

int empty(Heap *h) { return h->cnt == 0; }

Zombie *top(Heap *h) { return h->data[1]; }

int push(Heap *h, Zombie *z) {
    if (!h) return 0;
    if (h->cnt == h->size) return 0;
    h->data[++h->cnt] = z;
    int ind = h->cnt;
    while (ind >> 1 && cmp(h->data[ind], h->data[ind >> 1])) {
        swap(h->data[ind], h->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

void update(Heap *h, int ind, int n) {
    while ((ind << 1) <= n) {
        int cur_max = ind, l = ind << 1, r = ind << 1 | 1;
        if (cmp(h->data[l], h->data[cur_max])) cur_max = l;
        if (r <= n && cmp(h->data[r], h->data[cur_max])) cur_max = r;
        if (cur_max == ind) break;
        swap(h->data[cur_max], h->data[ind]);
        ind = cur_max;
    }
    return;
}

int pop(Heap *h) {
    if (!h) return 0;
    if (empty(h)) return 0;
    h->data[1] = h->data[h->cnt--];
    update(h, 1, h->cnt);
    return 1;
}

void update_zombie_dis(Heap *h) {
    if (!h) return;
    for (int i = 1; i <= h->cnt; ++i) {
        h->data[i]->now_dis += h->data[i]->speed;
    }
    for (int i = h->cnt >> 1; i >= 1; --i) {
        update(h, i, h->cnt);
    }
    return;
}

void clear_heap(Heap *h) {
    free(h->data);
    free(h);
    return;
}

void output(Heap *h) {
    if (!h) return;
    printf("\n========LOG========\n");
    for (int i = 1; i <= h->cnt; ++i) {
        printf("%d-%d ", h->data[i]->id, h->data[i]->now_dis);
    }
    printf("\n===================\n");
}

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        Heap *h = (Heap *)malloc(sizeof(Heap));
        int n, first_spd, speed;
        scanf("%d", &n);
        init_heap(h, n + 5);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &first_spd, &speed);
            push(h, get_new_zombie(i, first_spd, speed));
        }
        printf("Case #%d:\n", ++kase);
        for (int i = 0; i < n; ++i) {
            // output(h);
            i &&printf(" ");
            printf("%d", top(h)->id);
            pop(h);
            update_zombie_dis(h);
        }
        printf("\n");
        clear_heap(h);
    }
    return 0;
}
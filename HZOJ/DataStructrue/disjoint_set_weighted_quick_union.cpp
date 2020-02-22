// Weighted Quick-Union算法 时间复杂度稳定O(logn) 按秩合并 size存储节点个数
// HZOJ#71 未经过路径压缩 128ms 路径压缩后124ms
//一般只保留路径压缩就可以达到时间上的优化 可以不使用按秩优化节省内存空间
#include <stdio.h>
#include <stdlib.h>

#define swap(a, b)                \
    {                             \
        __typeof(a) __temp = (a); \
        (a) = (b);                \
        (b) = __temp;             \
    }

typedef struct UnionSet {
    int *father, *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1));
    u->size = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; ++i) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}

int find(UnionSet *u, int x) {
    // Path Compression
    return u->father[x] = (u->father[x] == x ? x : find(u, u->father[x]));
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) swap(fa, fb);
    u->father[fb] = fa;
    u->size[fa] += u->size[fb];
    return 1;
}

void clear(UnionSet *u) {
    if (!u) return;
    free(u->father);
    free(u->size);
    free(u);
    return;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1:
                merge(u, b, c);
                break;
            case 2:
                printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No");
                break;
        }
    }
    clear(u);
    return 0;
}
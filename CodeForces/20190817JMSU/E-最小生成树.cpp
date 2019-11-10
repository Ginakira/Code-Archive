#include <iostream>
#include <algorithm>
using namespace std;

int pre[100010];
int fib[100];

int find(int key) {
    if(pre[key] == key) return key;
    return pre[key] = find(pre[key]);
}

void init(int n) {
    for(int i = 0; i <= n; ++i) pre[i] = i;
    return ;
}

void fib_init() {
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3; fib[i] <= 100000; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return ;
}

struct Edge {
    int u, v, c;
};

void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if(rx != ry) {
        pre[rx] = ry;
    }
    return ;
}

Edge edge[100010];

bool cmp_low(Edge a, Edge b) {return a.c < b.c;}
bool cmp_high(Edge a, Edge b) {return a.c > b.c;}


int main() {
    ios::sync_with_stdio(false);
    int t, kase = 1;
    cin >> t;
    fib_init();
    while(t--) {
        int n, m;
        cin >> n >> m;
        init(n);
        for(int i = 0; i < m; ++i) {
            cin >> edge[i].u >> edge[i].v >> edge[i].c;
            merge(edge[i].u, edge[i].v);
        }
        
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(pre[i] == i)cnt++; 
        }

        cout << "Case #" << kase++ << ": ";
        if(cnt > 1) {
            cout << "No\n";
            continue;
        }
        int low = 0, high = 0;
        sort(edge, edge + m, cmp_low);
        init(n);
        for(int i = 0; i < m; ++i) {
            int ru = find(edge[i].u);
            int rv = find(edge[i].v);
            if(ru == rv) continue;
            low += edge[i].c;
            merge(edge[i].u, edge[i].v);
        }

        sort(edge, edge + m, cmp_high);
        init(n);
        for(int i = 0; i < m; ++i) {
            int ru = find(edge[i].u);
            int rv = find(edge[i].v);
            if(ru == rv) continue;
            high += edge[i].c;
            merge(edge[i].u, edge[i].v);
        }

        bool ans = false;
        for(int i = 1; fib[i] <= 100000; ++i) {
            if(fib[i] >= low && fib[i] <= high) {
                ans = true;
                break;
            }
        }
        if(ans) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
#include <iostream>
using namespace std;

int pre[1010], rk[1010];

void init() {
    for(int i = 0; i <= 1009; ++i) {
        pre[i] = i;
        rk[i] = 1;
    }
    return ;
}

int find(int key) {
    if(pre[key] == key) return key;
    return find(pre[key]);
}

void merge(int a, int b) {
    int roota = find(a);
    int rootb = find(b);
    if(roota != rootb) {
        pre[rootb] = roota;
        rk[roota] += rk[rootb];
    }
}

int main() {
    int n, m;
    while(cin >> n) {
        if(n == 0) break;
        cin >> m;
        init();
        int x, y;
        for(int i = 1; i <= m; ++i) {
            cin >> x >> y;
            merge(x, y);
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(pre[i] == i) ans++;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}
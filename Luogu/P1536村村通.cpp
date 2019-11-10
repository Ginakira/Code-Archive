#include <iostream>
using namespace std;

int pre[1010];

void init(int n) {
    for(int i = 0; i <= n; ++i) {
        pre[i] = i;
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
    }
    return ;
}

int main() {
    int n, m;
    while(cin >> n) {
        if(n == 0) break;
        cin >> m;
        init(n);
        int x, y;
        for(int i = 0; i < m; ++i) {
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
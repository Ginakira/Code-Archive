#include <iostream>
using namespace std;

int pre[100010];

void init(int n) {
    for(int i = 0; i <= n; ++i) pre[i] = i;
    return ;
}

int find(int key) {
    if(pre[key] == key) return key;
    return pre[key] = find(pre[key]);
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
    cin >> n >> m;
    init(n);
    int p, q;
    for(int i = 0; i < m; ++i) {
        cin >> p >> q;
        merge(p, q);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(find(i) == i) ans++;
    }
    cout << ans << endl;
    return 0;
}
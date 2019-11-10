#include <iostream>
using namespace std;

int pre[5050];

void init(int n) {
    for(int i = 0; i <= n; ++i) {
        pre[i] = i;
    }
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
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    init(n);
    int p1, p2;
    for(int i = 0; i < m; ++i) {
        cin >> p1 >> p2;
        merge(p1, p2);
    }
    for(int i = 0; i < p; ++i) {
        cin >> p1 >> p2;
        if(find(p1) == find(p2)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
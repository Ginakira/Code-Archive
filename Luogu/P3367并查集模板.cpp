#include <iostream>
using namespace std;

int pre[10001];

void init(int n) {
    for(int i = 0; i <= n; ++i) {
        pre[i] = i;
    }
}

int find(int key) {
    if(pre[key] == key) return key;
    return pre[key] = find(pre[key]);
}

void merge(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if(rootx != rooty) {
        pre[rooty] = rootx;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    int op, tmp1, tmp2;
    for(int i = 0; i < m; ++i) {
        cin >> op;
        if(op == 1) {
            cin >> tmp1 >> tmp2;
            merge(tmp1, tmp2);
        }
        else {
            cin >> tmp1 >> tmp2;
            if(find(tmp1) == find(tmp2)) cout << "Y\n";
            else cout << "N\n";
        }
    }
    return 0;
}
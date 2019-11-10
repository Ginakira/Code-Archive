#include <iostream>
using namespace std;

int pre[500010];
int rk[500010];

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        pre[i] = i;
        rk[i] = 1;
    }
    return ;
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
        rk[rootx] += rk[rooty];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    int p, tmp1, tmp2;
    for(int i = 0; i < m; ++i) {
        cin >> p;
        if(p == 0) continue;
        if(p == 1) {
            cin >> tmp1;
            continue;
        }
        cin >> tmp1;
        for(int j = 1; j < p; ++j) {
            cin >> tmp2;
            merge(tmp1, tmp2);
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(i != 1) cout << ' ';
        cout << rk[find(i)];
    }
    /*
    for(int i = 1; i <= n; ++i) {
        if(i != 1) cout << ' ';
        cout << rk[i];
    }
    cout << endl;
    */
    return 0;
}
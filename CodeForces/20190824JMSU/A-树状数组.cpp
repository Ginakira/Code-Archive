#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int t, n;
int tree[500005];

int lowbit(int x) {return x & (-x);}

void add(int k, int num) {
    while(k <= n) {
        tree[k] += num;
        k += lowbit(k);
    }
}

int query(int k) {
    int sum = 0;
    while(k) {
        sum += tree[k];
        k -= lowbit(k);
    }
    return sum;
}

int main() {
    string op;
    cin >> t;
    int kase = 0;
    while(t--) {
        memset(tree, 0, sizeof(tree));
        cin >> n;
        int tmp;
        for(int i = 1; i <= n; ++i) {
            cin >> tmp;
            add(i, tmp);
        }
        int i, j;
        cout << "Case " << ++kase << ':' << endl;
        while(true) {
            cin >> op;
            if(op[0] == 'E') break;
            if(op[0] == 'A') {
                cin >> i >> j;
                add(i, j);
            }
            else if(op[0] == 'S') {
                cin >> i >> j;
                add(i, -j);
            }
            else {
                cin >> i >> j;
                cout << query(j) - query(i - 1) << endl;
            }
        }
    }
    return 0;
}
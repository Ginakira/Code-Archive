#include <iostream>
using namespace std;

int tree[500005];
int n;

int lowbit(int a) {return a & (-a);}

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
    int m, tmp;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> tmp;
        add(i, tmp);
    }
    int op, i, j, num;
    for(int k = 0; k < m; ++k) {
        cin >> op;
        if(op == 1) {
            cin >> i >> num;
            add(i, num);
        }
        else {
            cin >> i >> j;
            tmp = query(j) - query(i - 1);
            cout << tmp << endl;
        }
    }
    return 0;
}
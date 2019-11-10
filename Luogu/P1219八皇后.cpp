#include <iostream>
using namespace std;

int a[233], b[233], c[233], d[233];
int ans, n;

void print() {
    if(ans <= 2) {
        for(int k = 1; k <= n; ++k) {
            cout << a[k] << ' ';
        }
        cout << endl;
    }
    ans++;
}

void dfs(int i) {
    if(i > n) {
        print();
        return ;
    }
    else {
        for(int j = 1; j <= n; ++j) {
            if((!b[j]) && (!c[i + j]) && (!d[i - j + n])) {
                a[i] = j;
                b[j] = 1;
                c[i + j] = 1;
                d[i - j + n] = 1;
                dfs(i + 1);
                b[j] = 0;
                c[i + j] = 0;
                d[i - j + n] = 0;
            }
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int a[100];
int f[100];

int main() {
    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int pre = -1, j = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] != pre) {
            f[j++] = a[i];
            pre = a[i];
        }
    }
    bool solved = false;
    for(int i = 0; i <= j - 2; ++i) {
        /* cout << "#a" << i << ' ' << a[i] << "  ";
        cout << "#a" << i + 1 << ' ' << a[i + 1] << "  ";
        cout << "#a" << i + 2 << ' ' << a[i + 2] << endl; */
        if(f[i + 2] - f[i + 1] == 1 && f[i + 1] - f[i] == 1) solved = true;
    }
    if(solved) cout << "YES";
    else cout << "NO";
    return 0;
}
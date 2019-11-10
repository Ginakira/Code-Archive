#include <iostream>
using namespace std;
#define MAXN 100001
int a[MAXN];
int b[MAXN];
int main() {
    int n, m, ans = 0;
    int aj = 0, bj = 0;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] % 2 == 1) aj++;
    }
    for(int i = 0; i < m; ++i) {
        cin >> b[i];
        if(b[i] % 2 == 1) bj++;
    }
    int ao = n - aj;
    int bo = m - bj;
    ans += min(bj, ao);
    ans += min(aj, bo);
    cout << ans << endl;
    return 0;
}
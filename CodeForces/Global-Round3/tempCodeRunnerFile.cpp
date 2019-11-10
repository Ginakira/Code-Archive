#include <iostream>
using namespace std;

long long n, m, ta, tb, k;
long long a[200001], b[200001];
int main() {
    cin >> n >> m >> ta >> tb >> k;
    for(long long i = 1; i <= n; ++i) cin >> a[i];
    for(long long i = 1; i <= m; ++i) cin >> b[i];
    if(k >= n) {
        cout << -1 << endl;
        return 0;
    }
    long long arb = a[k] + ta, arc;
    if(k == 1) arb = a[k + 1] + ta;
    //cout << arb << endl;
    bool fin = false;
    for(long long i = 1; i <= m; ++i) {
        if(i == m && b[i] >= arb) {
            fin = true;
            arc = b[i] + tb;
            break;
        }
        if(k == 1 && b[i] >= arb) {
            fin = true;
            arc = b[i] + tb;
            break;
        }
        if(b[i] >= arb) {
            fin = true;
            arc = b[i + 1] + tb;
            break;
        }
    }
    if(!fin) cout << -1 << endl;
    else cout << arc << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int pre[1010], beh[1010];
int main() {
    int n, sump = 0, sumb = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> pre[i], sump += pre[i];
    for(int i = 0; i < n; ++i) cin >> beh[i], sumb += pre[i];
    if(sump != sumb) {
        for(int i = 0; i < n; ++i) cout << pre[i] << ' ';
        for(int i = 0; i < n - 1; ++i) cout << beh[i] << ' ';
        cout << beh[n - 1] << endl;
        return 0;
    }
    sort(pre, pre + n);
    sort(beh, beh + n);
    for(int i = 0; i < n; ++i) {
        if(pre[i] != beh[i]) {
            swap(pre[i], beh[i]);
            break;
        }
    }
    sump = 0, sumb = 0;
    for(int i = 0; i < n; ++i) sump += pre[i];
    for(int i = 0; i < n; ++i) sumb += beh[i];
    if(sump == sumb) {
        cout << -1 << endl;
        return 0;
    }
    //cout << sump << sumb << endl;
    for(int i = 0; i < n; ++i) cout << pre[i] << ' ';
    for(int i = 0; i < n - 1; ++i) cout << beh[i] << ' ';
    cout << beh[n - 1] << endl;
    return 0;
}
#include <iostream>
using namespace std;

int n, m;

int find(int *a) {
    int tmp = 0;
    for(int i = 1; i < n; ++i) {
        if(a[i] < a[i - 1]) tmp++;
    }
    return tmp;
}

int a[300010];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k, ans = 0;
    k = find(a);
    while(k != 0) {
        for(int i = 1; i < n; ++i) {
            if(a[i] < a[i - 1]) {
                cout << i << endl;
                a[i] = (a[i] + 1) % m;
            }
        }
        cout << endl << endl;
        ans++;
        k = find(a);
    }
    cout << ans << endl;
    return 0;
}
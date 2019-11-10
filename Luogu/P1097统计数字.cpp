#include <iostream>
#include <algorithm>
using namespace std;

int a[200001];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = 1, pre = a[0];
    for(int i = 1; i < n; ++i) {
        if(a[i] != pre) {
            cout << pre << ' ' << cnt << endl;
            cnt = 1;
            pre = a[i];
        }
        else {
            cnt++;
        }
    }
    cout << pre << ' ' << cnt << endl;
    return 0;
}
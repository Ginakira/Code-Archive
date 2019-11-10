#include <iostream>
using namespace std;

int a[100001];

int main() {
    int n, tmp, maxl = 1;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int pre = a[0];
    tmp = 1;
    for (int i = 1; i < n; ++i) {
        if(a[i] >= pre)
            tmp++;
        else
            tmp = 1;
        pre = a[i];
        maxl = max(maxl, tmp);
    }
    cout << maxl;
    return 0;
}
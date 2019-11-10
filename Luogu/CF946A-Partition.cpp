#include <iostream>
#include <algorithm>
using namespace std;

int a[233];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int csum = 0, bsum = 0, i = 0;
    for(i = 0; a[i] <= 0; i++) csum += a[i];
    for(; i < n; ++i) bsum += a[i];
    //cout << bsum << endl << csum << endl;
    cout << bsum - csum;
    return 0;
}
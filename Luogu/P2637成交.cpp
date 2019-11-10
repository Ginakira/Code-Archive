#include <iostream>
#include <algorithm>
using namespace std;

int a[1010];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a, a + m);
    int compare = m - n - 1;
    if(compare < 0) compare = 0;
    int max = 0, price, maxi;
    for(int i = compare; i < m; ++i) {
        price = a[i];
        if((price * (m - i)) > max) {
            max = price * (m - i);
            maxi = price;
        }
    }
    cout << maxi << ' ' << max << endl;
    return 0;
}
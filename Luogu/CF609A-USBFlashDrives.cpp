#include <iostream>
#include <algorithm>
using namespace std;

int capa[1010];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> capa[i];
    sort(capa, capa + n);
    reverse(capa, capa + n);
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        sum += capa[i];
        cnt++;
        if (sum >= m)
            break;
    }
    cout << cnt;
    return 0;
}
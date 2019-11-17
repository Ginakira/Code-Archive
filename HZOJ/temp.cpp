#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, m, book[110];
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> book[i];
    }
    sort(book, book + n);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (book[i] < 0) ans -= book[i];
    }
    cout << ans << endl;
    return 0;
}
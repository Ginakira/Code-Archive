#include <iostream>
#include <algorithm>
using namespace std;

int cnt[233] = {0};

int main() {
    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> tmp, cnt[tmp]++;
    sort(cnt, cnt + 101);
    reverse(cnt, cnt + 101);
    cout << cnt[0];
    return 0;
}
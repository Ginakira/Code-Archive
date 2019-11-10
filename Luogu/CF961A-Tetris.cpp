#include <iostream>
#include <map>
#include <climits>
using namespace std;

map<int,int> cnt;

int main() {
    int n, m, tmp;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> tmp;
        cnt[tmp]++;
    }
    int min = INT_MAX;
    for(int i = 1; i <= n; ++i) {
        min = cnt[i] < min ? cnt[i] : min;
    }
    cout << min << endl;
    return 0;
}
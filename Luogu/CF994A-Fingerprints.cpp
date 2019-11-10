#include <iostream>
#include <queue>
#include <map>
using namespace std;

queue<int> ans;
map<int, int> fin;

int pass[15];

int main() {
    int n, m, tmpf;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> pass[i];
    for (int i = 0; i < m; ++i) {
        cin >> tmpf;
        fin[tmpf] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (fin[pass[i]] == 1) ans.push(pass[i]);
    }
    while(!ans.empty()) {
        cout << ans.front() << ' ';
        ans.pop();
    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int s[30];
bool used[30];
int n, m, target;

bool cmp(int a, int b) {
    return a > b;
}

bool dfs(int cnt, int now, int rem) {
    if(cnt == 3) return true;
    for(int i = now; i < m; ++i) {
        if(used[i]) continue;
        used[i] = true;
        if(s[i] == rem) {
            if(dfs(cnt + 1, 0, target)) return true;
        }
        else if(s[i] < rem) {
            if(dfs(cnt, i + 1, rem - s[i])) return true;
        }
        used[i] = false;
    }
    return false;
}

int main() {
    cin >> n;
    ios::sync_with_stdio(false);
    while(n--) {
        cin >> m;
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            cin >> s[i];
            sum += s[i];
        }
        if(sum % 4 != 0) {
            cout << "no\n";
            continue;
        }
        memset(used, false, sizeof(used));
        target = sum / 4;
        sort(s, s + m, cmp);
        if(dfs(0, 0, target)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}

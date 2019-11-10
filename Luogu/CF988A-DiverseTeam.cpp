#include <iostream>
#include <queue>
using namespace std;

queue<int> ans;
int flag[233] = {0};

int main() {
    int n, k, tmp;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        if (!flag[tmp]) {
            ans.push(i);
            flag[tmp] = 1;
        }
    }
    if(ans.size() >= k) {
        cout << "YES\n";
        int len = ans.size() - k;
        while (ans.size() > len) {
            cout << ans.front() << ' ';
            ans.pop();
        }
    }
    else
        cout << "NO\n";
    return 0;
}
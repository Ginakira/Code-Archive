#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int q[100001];
set <pair<int, int> > s;
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        q[x] = 1;
        s.insert({x, x});
        if(q[x - 1]) s.insert({x, x - 1});
        if(q[x + 1]) s.insert({x, x + 1});
    }
    int ans = 3 * n - 2 - s.size();
    cout << ans << endl;
    return 0;
}
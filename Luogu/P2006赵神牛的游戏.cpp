#include <iostream>
using namespace std;


int cost[30100], hurt[30100], ans[30100];
int main() {
    int k, m, n, t;
    cin >> k >> m >> n;
    int j = 0;
    bool solved = false;
    for(int i = 1; i <= m; ++i) {
        cin >> cost[i] >> hurt[i];
        if(cost[i] == 0 && hurt[i] != 0) ans[j++] = i;
        else {
            if(cost[i] != 0) t = k / cost[i];
            if(t * hurt[i] >= n) ans[j++] = i, solved = true;
        }
    }
    if(!solved) cout << -1 << endl;
    for(int i = 0; i < j && solved; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

struct Apple {
    int hei;
    int power;
};

bool cmp(Apple a, Apple b) {
    return a.power < b.power;
}

int main() {
    int n, s, a, b;
    int ans = 0;
    cin >> n >> s >> a >> b;
    Apple app[n];
    for(int i = 0; i < n; ++i) {
        cin >> app[i].hei >> app[i].power;
    }
    sort(app, app + n, cmp);
    for(int i = 0; i < n; ++i) {
        if(a + b >= app[i].hei && app[i].power <= s) {
            s -= app[i].power;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;    
}
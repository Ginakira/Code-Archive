#include <iostream>
using namespace std;

int cost[10];

int main() {
    for(int i = 1; i <= 4; ++i) cin >> cost[i];
    int ans = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); ++i) ans += cost[s[i] - '0'];
    cout << ans << endl;
    return 0;
}
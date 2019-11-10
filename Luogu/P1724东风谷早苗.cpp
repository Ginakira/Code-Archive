#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;

LL t, x, y;
LL stat[4];
LL stat2[4];
int main() {
    string s;
    cin >> s;
    cin >> t;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'N') stat[0]++;
        else if(s[i] == 'S') stat[1]++;
        else if(s[i] == 'W') stat[2]++;
        else stat[3]++;
    }
    int dx = stat[3] - stat[2];
    int dy = stat[0] - stat[1];
    LL tmp = t / s.size();
    LL tmp2 = t % s.size();
    //cout << tmp << ' ' << tmp2 << endl;
    x += tmp * dx, y += tmp * dy;
    //cout << x << ' ' << y << endl;
    string s2 = s.substr(0, tmp2);
    for(int i = 0; i < s2.size(); ++i) {
        if(s[i] == 'N') stat2[0]++;
        else if(s[i] == 'S') stat2[1]++;
        else if(s[i] == 'W') stat2[2]++;
        else stat2[3]++;
    }
    dx = stat2[3] - stat2[2];
    dy = stat2[0] - stat2[1];
    x += dx, y += dy;
    cout << x << ' ' << y << endl;
    return 0;
}
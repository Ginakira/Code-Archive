#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

struct City {
    int p, dis;
    string name;
};

bool cmp(City a, City b) {
    return a.dis < b.dis;
}

City c[200];
string min_city = "Moscow";
int mincost = INT_MAX;

int main() {
    int n;
    for(n = 0; ; ++n) {
        cin >> c[n].p >> c[n].dis >> c[n].name;
        if(c[n].dis == 0) break;
    }
    sort(c, c + n, cmp);
    for(int i = 0; i <= n; ++i) {
        int cost = 0;
        for(int j = 0; j <= n; ++j) {
            if(j == i) continue;
            cost += c[j].p * abs(c[j].dis - c[i].dis);
        }
        //cout << "#" << c[i].name << ' ' << cost << endl;
        min_city = cost < mincost ? c[i].name : min_city;
        mincost = min(mincost, cost);
    }
    cout << min_city << ' ' << mincost << endl;
    return 0;
}
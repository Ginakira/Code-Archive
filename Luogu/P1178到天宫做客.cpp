#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long LL;

struct Day {
    int m, d;
};

Day d[370];

bool cmp (Day a, Day b) {
    if(a.m == b.m) return a.d < b.d;
    return a.m < b.m;
}

int md[15] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
int date[370];

int main() {
    LL n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> d[i].m >> d[i].d;
        date[md[d[i].m] + d[i].d] = 1;
    }
    int maxd = 0, tmp = 0;
    for(int i = 1; i <= 366; ++i) {
        if(date[i] == 1) tmp = 0;
        else tmp++;
        maxd = max(maxd, tmp);
    }
    double k = maxd * 86400.0 / 366;
    cout << fixed << setprecision(0) << k << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;

struct Data {
    int x, y;
};

Data mac[100010];
Data tsk[100010];

bool cmp(Data a, Data b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x > b.x;
}

int main() {
    int m, n, cnt = 0, mon = 0;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> mac[i].x >> mac[i].y;
    }
    for (int i = 0; i < n; ++i) {
        cin >> tsk[i].x >> tsk[i].y;
    }
    sort(mac, mac + m, cmp);
    sort(tsk, tsk + n, cmp);

    for (int i = 0, j = 0; i < n; ++i) {
        
    }
    cout << cnt << ' ' << mon << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

struct machine {
    int workt, mlev;
};

struct tasks {
    int needt, tlev;
};

machine mac[100010];
tasks tsk[100010];


bool cmp1(machine a, machine b) {
    if (a.workt == b.workt) return a.mlev > b.mlev;
    return a.workt > b.workt;
}

bool cmp2(tasks a, tasks b) {
    if (a.needt == b.needt) return a.tlev > b.tlev;
    return a.needt > b.needt;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        int cnt = 0;
        long long int sum = 0;
        int tmp[233];
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < n; ++i) {
            cin >> mac[i].workt >> mac[i].mlev;
        }
        for (int i = 0; i < m; ++i) {
            cin >> tsk[i].needt >> tsk[i].tlev;
        }
        sort(mac, mac + n, cmp1);
        sort(tsk, tsk + m, cmp2);
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && mac[j].workt >= tsk[i].needt) {
                tmp[mac[j].mlev]++;
                ++j;
            }
            for (int k = tsk[i].tlev; k <= 100; ++k) {
                if (tmp[k]) {
                    tmp[k]--;
                    sum += (tsk[i].needt * 500 + tsk[i].tlev * 2);
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << ' ' << sum << endl;
    }
    return 0;
}
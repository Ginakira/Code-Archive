#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> ballon;

struct Kid {
    int id, h, ans;
};

Kid kid[100010];

bool cmp(Kid a, Kid b) { return a.h < b.h; }
bool cmp2(Kid a, Kid b) { return a.id < b.id; }

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> kid[i].h;
        kid[i].id = i;
    }
    int tmp;
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        ballon.push_back(tmp);
    }
    sort(ballon.begin(), ballon.end());
    sort(kid, kid + n, cmp);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        if (ballon.empty())
            kid[i].ans = 0;
        else {
            while (!ballon.empty() && ballon[0] <= kid[i].h) {
                cnt++;
                ballon.erase(ballon.begin());
            }
            kid[i].ans = cnt;
        }
    }
    sort(kid, kid + n, cmp2);
    for (int i = 0; i < n; ++i) {
        cout << kid[i].ans << endl;
    }
    return 0;
}
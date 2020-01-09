#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct stu {
    string s;
    int num;
} w[1001];

bool cmp(stu a, stu b) {
    if (a.s.size() != b.s.size())
        return a.s.size() > b.s.size();
    else {
        for (int i = 0; i < b.s.size(); i++) {
            return a.s[i] > b.s[i];
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i].s;
        w[i].num = i + 1;
    }
    sort(w, w + n, cmp);
    cout << w[0].num << endl;
    cout << w[0].s << endl;
    return 0;
}
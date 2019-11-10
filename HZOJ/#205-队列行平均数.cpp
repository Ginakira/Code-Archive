#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n, m, stu;
    double ans[33];
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < m; ++j) {
            cin >> stu;
            sum += stu;
        }
        ans[i] = sum / m;
    }
    cout << setiosflags(ios::fixed) << setprecision(6);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
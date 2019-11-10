#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int para[7] = {0}, num[33];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        if (num[i] == 100)
            para[1]++;
        else if (num[i] >= 90)
            para[2]++;
        else if (num[i] >= 80)
            para[3]++;
        else if (num[i] >= 70)
            para[4]++;
        else if (num[i] >= 60)
            para[5]++;
        else
            para[6]++;
    }
    sort(num, num + n, greater<int>());
    for (int i = 0; i < n; ++i) {
        cout << num[i] << endl;
    }
    for (int i = 1; i <= 6; ++i) {
        if (i != 1) cout << ' ';
        cout << para[i];
    }
    return 0;
}
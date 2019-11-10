#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int car[10010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> car[i];
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (car[j] > car[j + 1]) {
                cnt++;
                swap(car[j], car[j + 1]);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
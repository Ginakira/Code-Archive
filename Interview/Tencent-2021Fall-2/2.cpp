// AC
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
const int MAX_N = 100000;

int factors[MAX_N + 1];

void cal_facs(int max_val) {
    for (int i = 1; i <= max_val; ++i) {
        factors[i] = 1;
        int n = i;
        for (int j = 2; j * j <= n; j++) {
            if (n % j == 0) {
                int a = 0;
                while (n % j == 0) {
                    n /= j;
                    a++;
                }
                factors[i] = factors[i] * (a + 1);
            }
        }
        if (n > 1) factors[i] *= 2;
    }
}

int main() {
    int n;
    cin >> n;
    int max_val = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        max_val = max(max_val, b[i]);
    }
    cal_facs(max_val);
    for (int i = 0; i < n; ++i) {
        a[i] = factors[a[i]];
        b[i] = factors[b[i]];
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int finished = 0, win = 0;
    int la = 0, ra = n - 1;
    int lb = 0, rb = n - 1;
    while (finished < n) {
        if (a[la] > b[lb]) {
            ++win;
            ++la, ++lb;
        } else if (a[la] < b[lb]) {
            --ra, ++lb;
        } else {
            if (a[ra] > b[rb]) {
                ++win;
                --ra, --rb;
            } else {
                --ra, ++lb;
            }
        }
        ++finished;
    }
    cout << win << endl;
    return 0;
}
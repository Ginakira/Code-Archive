#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int max_sum = 0;
    tuple<int, int, int> ans{0, 0, 0};
    int na = n / a, nb = n / b, nc = n / c;
    for (int i = 0; i <= na; ++i) {
        int sum = a * i;
        if (sum > n) break;
        for (int j = 0; j <= nb; ++j) {
            sum += b * j;
            if (sum > n) break;
            for (int k = 0; k <= nc; ++k) {
                sum += c * k;
                if (sum > n) break;
                if (sum != n) continue;
                tuple<int, int, int> t{i, j, k};
                if (sum == max_sum) {
                    if (t > ans) {
                        ans = t;
                    }
                } else if (sum > max_sum) {
                    ans = t;
                }
            }
        }
    }
    if (ans == tuple<int, int, int>{0, 0, 0}) {
        cout << -1 << endl;
    } else {
        auto [ac, bc, cc] = ans;
        cout << ac << ' ' << bc << ' ' << cc << endl;
    }
    return 0;
}
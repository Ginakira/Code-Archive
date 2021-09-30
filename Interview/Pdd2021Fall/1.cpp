#include <algorithm>
#include <iostream>
#include <limits>
#include <tuple>
#include <vector>
using namespace std;

void dfs(int a, int b, int c, int cur_a, int cur_b, int cur_c, int remain,
         tuple<int, int, int> &best_ans) {
    if (remain == 0) {
        cout << cur_a << ' ' << cur_b << ' ' << cur_c << endl;
        auto [ac, bc, cc] = best_ans;
        int sum_best_ans = ac + bc + cc, sum_ans = cur_a + cur_b + cur_c;
        if (sum_best_ans == sum_ans) {
            tuple<int, int, int> ans{cur_a, cur_b, cur_c};
            if (ans > best_ans) {
                best_ans = ans;
            }
        } else if (sum_ans > sum_best_ans) {
            best_ans = make_tuple(cur_a, cur_b, cur_c);
        }
        return;
    }
    if (remain >= a) {
        dfs(a, b, c, cur_a + 1, cur_b, cur_c, remain - a, best_ans);
    }
    if (remain >= b) {
        dfs(a, b, c, cur_a, cur_b + 1, cur_c, remain - b, best_ans);
    }
    if (remain >= c) {
        dfs(a, b, c, cur_a, cur_b, cur_c + 1, remain - c, best_ans);
    }
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    tuple<int, int, int> ans{-1, -1, -1};
    dfs(a, b, c, 0, 0, 0, n, ans);
    if (ans == tuple<int, int, int>{-1, -1, -1}) {
        cout << -1 << endl;
    } else {
        auto [ac, bc, cc] = ans;
        cout << ac << ' ' << bc << ' ' << cc << endl;
    }
    return 0;
}
// LeetCode 2312 卖木头块

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    long long sellingWood(int m, int n, vector<vector<int>> &prices) {
        auto pair_hash = [](const pair<int, int> &p) {
            return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
        };
        unordered_map<pair<int, int>, int, decltype(pair_hash)> hw_to_price;
        for (auto &price : prices) {
            int h = price[0], w = price[1], p = price[2];
            hw_to_price[{h, w}] = p;
        }

        vector<vector<long long>> mem(m + 1, vector<long long>(n + 1, -1));
        function<long long(int, int)> f = [&](int h, int w) {
            if (mem[h][w] != -1) {
                return mem[h][w];
            }
            long long ans = hw_to_price[{h, w}];
            if (h > 1) {
                for (int i = 1; i < h; ++i) {
                    ans = max(ans, f(h - i, w) + f(i, w));
                }
            }
            if (w > 1) {
                for (int i = 1; i < w; ++i) {
                    ans = max(ans, f(h, w - i) + f(h, i));
                }
            }
            mem[h][w] = ans;
            return ans;
        };
        return f(m, n);
    }
};

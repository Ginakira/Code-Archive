// LeetCode 1465 切割后面积最大的蛋糕

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
    int maxArea(int h, int w, vector<int>& horizontalCuts,
                vector<int>& verticalCuts) {
        static constexpr int MOD = 1e9 + 7;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        auto cal_max = [](const vector<int>& cuts, int last) {
            int pre = 0, max_cut = 0;
            for (const auto& cut : cuts) {
                max_cut = max(max_cut, cut - pre);
                pre = cut;
            }
            return max(max_cut, last - pre);
        };
        return 1LL * cal_max(horizontalCuts, h) * cal_max(verticalCuts, w) %
               MOD;
    }
};

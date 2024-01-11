// LeetCode 2525 根据规则将箱子分类

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
    string categorizeBox(int length, int width, int height, int mass) {
        bool is_bulky = false;
        bool is_heavy = mass >= 100;
        constexpr int dimension_threshold = 1e4, volume_threshold = 1e9;
        if (max({length, width, height}) >= dimension_threshold ||
            1L * length * width * height >= volume_threshold) {
            is_bulky = true;
        }

        if (is_bulky && is_heavy) {
            return "Both";
        }
        return is_bulky ? "Bulky" : (is_heavy ? "Heavy" : "Neither");
    }
};

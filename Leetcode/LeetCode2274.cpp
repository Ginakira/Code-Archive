// LeetCode 2274 不含特殊楼层的最大连续楼层数

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
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        special.emplace_back(bottom - 1);
        special.emplace_back(top + 1);
        ranges::sort(special);
        int n = special.size();
        int max_floors = 0;
        for (int i = 1; i < n; ++i) {
            max_floors = max(max_floors, special[i] - special[i - 1] - 1);
        }
        return max_floors;
    }
};
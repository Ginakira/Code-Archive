// LeetCode 3208 交替组II

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
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        colors.reserve(colors.size() + k);
        for (int i = 0; i < k - 1; ++i) {
            colors.emplace_back(colors[i]);
        }
        for (int l = 0, r = 1; r < colors.size(); ++r) {
            if (colors[r] == colors[r - 1]) {
                l = r;
            }
            if (r - l + 1 >= k) {
                ++ans;
            }
        }
        return ans;
    }
};

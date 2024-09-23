// LeetCode 1014 最佳观光组合

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
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int max_val = values[0] + 0;
        for (int i = 1; i < values.size(); ++i) {
            ans = max(ans, values[i] - i + max_val);
            max_val = max(max_val, values[i] + i);
        }
        return ans;
    }
};
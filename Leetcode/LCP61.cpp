// LCP 61 气温变化趋势

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
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int ans = 0;
        int cur = 0;
        int n = temperatureA.size();
        for (int i = 1; i < n; ++i) {
            auto da = temperatureA[i] <=> temperatureA[i - 1];
            auto db = temperatureB[i] <=> temperatureB[i - 1];
            if (da == db) {
                ++cur;
                ans = max(ans, cur);
            } else {
                cur = 0;
            }
        }
        return ans;
    }
};
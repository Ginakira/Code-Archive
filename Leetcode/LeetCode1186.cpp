// LeetCode 1186 删除一次得到子数组最大和

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
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int dp0 = arr[0], dp1 = 0, ans = arr[0];
        for (int i = 1; i < n; ++i) {
            dp1 = max(dp1 + arr[i], dp0);
            dp0 = max(dp0, 0) + arr[i];
            ans = max({ans, dp0, dp1});
        }
        return ans;
    }
};
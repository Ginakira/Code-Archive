// LeetCode 2028 找出缺失的观测数据

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
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int m_sum = std::accumulate(rolls.begin(), rolls.end(), 0);
        int n_sum = mean * (n + m) - m_sum;
        if (n_sum < n || n_sum > 6 * n) {
            return {};
        }
        vector<int> res(n, n_sum / n);
        for (int i = 0; i < n_sum % n; ++i) {
            ++res[i];
        }
        return res;
    }
};
// LeetCode 2178 拆分成最多数目的正偶数之和

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
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if (finalSum & 1) {
            return {};
        }
        for (int i = 2; i <= finalSum; i += 2) {
            ans.emplace_back(i);
            finalSum -= i;
        }
        ans.back() += finalSum;
        return ans;
    }
};
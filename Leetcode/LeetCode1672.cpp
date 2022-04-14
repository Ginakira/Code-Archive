// LeetCode 1672 最富有客户的资产总量

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_assets = 0;
        for (auto& account : accounts) {
            max_assets =
                max(accumulate(account.begin(), account.end(), 0), max_assets);
        }
        return max_assets;
    }
};
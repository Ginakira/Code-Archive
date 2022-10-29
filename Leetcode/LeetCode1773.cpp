// LeetCode 1773 统计匹配检索规则的物品数量

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countMatches(vector<vector<string>>& items, string ruleKey,
                     string ruleValue) {
        int key_ind = 0;
        if (ruleKey == "color") {
            key_ind = 1;
        } else if (ruleKey == "name") {
            key_ind = 2;
        }

        int cnt = 0;
        for (auto& item : items) {
            if (item[key_ind] == ruleValue) {
                ++cnt;
            }
        }
        return cnt;
    }
};
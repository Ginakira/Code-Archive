// LeetCode 2744 最大字符串匹配数目

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
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> us;
        int ans = 0;
        for (auto& word : words) {
            if (us.count(word)) {
                ++ans;
            } else {
                us.emplace(string(word.rbegin(), word.rend()));
            }
        }
        return ans;
    }
};
// LeetCode 2390 从字符串中移除星号

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
    string removeStars(string s) {
        string ans;
        for (char c : s) {
            if (c == '*' && !ans.empty()) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
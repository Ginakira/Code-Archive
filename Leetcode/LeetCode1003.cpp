// LeetCode 1003 检查替换后的词是否有效

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
    bool isValid(string s) {
        string stk;
        for (char ch : s) {
            stk.push_back(ch);
            if (stk.size() >= 3 && stk.substr(stk.size() - 3) == "abc") {
                stk.erase(stk.end() - 3, stk.end());
            }
        }
        return stk.empty();
    }
};
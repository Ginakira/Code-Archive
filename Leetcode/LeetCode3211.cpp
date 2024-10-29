// LeetCode 3211 生成不含相邻零的二进制字符串

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
    vector<string> validStrings(int n) {
        vector<string> ans;
        string cur;
        function<void(string &)> backtrace = [&](string &cur) {
            if (cur.size() == n) {
                ans.emplace_back(cur);
                return;
            }
            cur.push_back('1');
            backtrace(cur);
            cur.pop_back();
            if (cur.empty() || cur.back() != '0') {
                cur.push_back('0');
                backtrace(cur);
                cur.pop_back();
            }
        };
        backtrace(cur);
        return ans;
    }
};
// LeetCode 2810 故障键盘

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
    string finalString(string s) {
        string cur;
        for (auto &ch : s) {
            if (ch == 'i') {
                ranges::reverse(cur);
            } else {
                cur += ch;
            }
        }
        return cur;
    }
};

class Solution2 {
   public:
    string finalString(string s) {
        deque<char> dq;
        bool is_rev = false;
        for (auto &ch : s) {
            if (ch != 'i') {
                if (is_rev) {
                    dq.push_front(ch);
                } else {
                    dq.push_back(ch);
                }
            } else {
                is_rev = !is_rev;
            }
        }
        string ans = (is_rev ? string(dq.rbegin(), dq.rend())
                             : string(dq.begin(), dq.end()));
        return ans;
    }
};
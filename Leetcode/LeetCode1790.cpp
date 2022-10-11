// LeetCode 1790 仅执行一次字符串交换能否使两个字符串相等

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        vector<int> diff;
        diff.reserve(2);
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (diff.size() >= 2) {
                    return false;
                }
                diff.push_back(i);
            }
        }
        if (diff.empty()) {
            return true;
        }
        if (diff.size() != 2) {
            return false;
        }
        return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
    }
};
// LeetCode 816 模糊座标

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    vector<string> get_permutation(string s) {
        vector<string> ans;
        if (s[0] != '0' || s == "0") {
            ans.emplace_back(s);
        }
        for (int pos = 1; pos < s.size(); ++pos) {
            if ((pos != 1 && s[0] == '0') || s.back() == '0') {
                continue;
            }
            ans.emplace_back(s.substr(0, pos) + "." + s.substr(pos));
        }
        return ans;
    }

   public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size() - 2;
        vector<string> ans;
        s = s.substr(1, n);
        for (int left_len = 1; left_len < n; ++left_len) {
            vector<string> left_perm = get_permutation(s.substr(0, left_len));
            if (left_perm.empty()) {
                continue;
            }
            vector<string> right_perm = get_permutation(s.substr(left_len));
            if (right_perm.empty()) {
                continue;
            }
            for (auto &left : left_perm) {
                for (auto &right : right_perm) {
                    ans.emplace_back("(" + left + ", " + right + ")");
                }
            }
        }
        return ans;
    }
};
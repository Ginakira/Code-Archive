// LeetCode 1763 最长的美好子字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestNiceSubstring(string s) {
        auto check = [](const string &s) {
            unordered_set<char> us;
            for (char c : s) {
                us.insert(c);
            }
            for (auto &c : us) {
                if (!((islower(c) && us.count(toupper(c)) ||
                       isupper(c) && us.count(tolower(c))))) {
                    return false;
                }
            }
            return true;
        };

        string ans;
        for (size_t i = 0, n = s.size(); i < n; ++i) {
            for (size_t j = 1; i + j <= n; ++j) {
                if (j <= ans.size()) continue;
                string temp = s.substr(i, j);
                if (check(temp)) {
                    ans = temp;
                }
            }
        }
        return ans;
    }
};
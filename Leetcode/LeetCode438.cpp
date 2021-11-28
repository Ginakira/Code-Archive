// LeetCode 438 找到字符串中所有字母异位词

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int len_s = s.size(), len_p = p.size();
        if (len_s < len_p) {
            return {};
        }
        vector<int> ans;
        vector<int> s_count(26, 0), p_count(26, 0);

        for (int i = 0; i < len_p; ++i) {
            ++p_count[p[i] - 'a'];
            ++s_count[s[i] - 'a'];
        }
        if (s_count == p_count) {
            ans.push_back(0);
        }
        for (int i = 0; i + len_p < len_s; ++i) {
            --s_count[s[i] - 'a'];
            ++s_count[s[i + len_p] - 'a'];
            if (s_count == p_count) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
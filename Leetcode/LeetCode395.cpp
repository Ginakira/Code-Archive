// LeetCode 395 至少有K个重复字符的最长子串
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 分治法
// 以区间内出现次数小于k的字符为分割点，求各段的答案，取最大值
class Solution {
   private:
    void split_string(const string &s, vector<string> &vec,
                      const char flag = ' ') {
        vec.clear();
        stringstream ss(s);
        string sub;
        while (getline(ss, sub, flag)) {
            vec.emplace_back(sub);
        }
    }

   public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) return 0;
        unordered_set<char> chars(s.begin(), s.end());
        unordered_map<char, int> counter;
        for (const char &c : s) {
            ++counter[c];
        }

        for (char c : chars) {
            if (counter[c] < k) {
                int result = 0;
                vector<string> sub_strings;
                split_string(s, sub_strings, c);
                for (const string &sub : sub_strings) {
                    result = max(result, longestSubstring(sub, k));
                }
                return result;
            }
        }
        return s.size();
    }
};
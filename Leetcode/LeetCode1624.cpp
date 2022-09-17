// LeetCode 1624 两个相同字符之间的最长子字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxLengthBetweenEqualCharacters(string s) {
        int max_ans = -1;
        vector<int> record(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            char c_ind = s[i] - 'a';
            if (record[c_ind] != -1) {
                max_ans = max(max_ans, i - record[c_ind] - 1);
            } else {
                record[c_ind] = i;
            }
        }
        return max_ans;
    }
};
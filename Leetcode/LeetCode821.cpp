// LeetCode 821 字符的最短距离

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> shortestToChar(string s, char c) {
        size_t n = s.size();
        vector<int> pos, result(n);
        for (size_t i = 0; i < n; ++i) {
            if (s[i] == c) {
                pos.push_back(i);
            }
        }
        for (size_t i = 0; i < n; ++i) {
            auto it = lower_bound(pos.begin(), pos.end(), i);
            int cur_pos = INT_MAX;
            if (it != pos.end()) {
                cur_pos = min(cur_pos, abs(*it - (int)i));
            }
            if (it != pos.begin()) {
                cur_pos = min(cur_pos, abs(*(it - 1) - (int)i));
            }
            result[i] = cur_pos;
        }
        return result;
    }
};
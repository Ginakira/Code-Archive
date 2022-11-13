// LeetCode 791 自定义字符串排序

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string customSortString(string order, string s) {
        array<int, 26> pos;
        for (int i = 0; i < order.size(); ++i) {
            pos[order[i] - 'a'] = i;
        }
        sort(s.begin(), s.end(),
             [&](char a, char b) { return pos[a - 'a'] < pos[b - 'a']; });
        return s;
    }
};
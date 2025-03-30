// LeetCode 2109 向字符串添加空格

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
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        auto it = spaces.begin();
        for (int i = 0; i < s.size(); ++i) {
            if (it != spaces.end() && *it == i) {
                res.push_back(' ');
                ++it;
            }
            res.push_back(s[i]);
        }
        return res;
    }
};
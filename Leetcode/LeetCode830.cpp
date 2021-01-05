// LeetCode 830 较大分组的位置
#include <string>
#include <vector>
using namespace std;

// 记录，一次遍历 4ms
class Solution {
   public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ret;
        for (int i = 0, pre = 0; i < s.size(); ++i) {
            if (i + 1 == s.size() || s[i] != s[i + 1]) {
                if (i - pre >= 2) {
                    ret.push_back({pre, i});
                }
                pre = i + 1;
            }
        }
        return ret;
    }
};
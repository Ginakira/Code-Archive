// LeetCode 455 分发饼干
#include <algorithm>
#include <vector>
using namespace std;

// Solution1: lower_bound + sort  152ms
class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ret = 0;
        sort(s.begin(), s.end());
        for (const int num : g) {
            auto lower = lower_bound(s.begin(), s.end(), num);
            if (lower != s.end()) {
                ++ret;
                s.erase(lower);
            }
        }
        return ret;
    }
};

// Solution2: 两边排序 一次遍历 88ms
class Solution2 {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gn = g.size(), sn = s.size(), ret = 0;
        for (int i = 0, j = 0; i < gn && j < sn; ++i, ++j) {
            while (j < sn && s[j] < g[i]) ++j;
            if (j < sn) ++ret;
        }
        return ret;
    }
};
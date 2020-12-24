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
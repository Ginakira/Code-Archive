// 剑指 Offer 61. 扑克牌中的顺子

#include <algorithm>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isStraight(vector<int>& nums) {
        int min_val = 23, max_val = 0;
        set<int> st;
        for (int num : nums) {
            if (num == 0) {
                continue;
            }
            if (st.count(num)) {
                return false;
            }
            st.insert(num);
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }
        return max_val - min_val < 5;
    }
};
// LeetCode 414 第三大的数
#include <set>
#include <vector>
using namespace std;

// set去重排序
class Solution {
   public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> sorted_nums(s.begin(), s.end());
        int n = sorted_nums.size();
        return n >= 3 ? sorted_nums[n - 3] : sorted_nums[n - 1];
    }
};

class Solution2 {
   public:
    int thirdMax(vector<int>& nums) {
        long m1 = LONG_MIN, m2 = LONG_MIN, m3 = LONG_MIN;
        for (int& num : nums) {
            if (num == m1 || num == m2 || num == m3) continue;
            if (num > m1) {
                m3 = m2, m2 = m1, m1 = num;
            } else if (num > m2) {
                m3 = m2, m2 = num;
            } else if (num > m3) {
                m3 = num;
            }
        }
        return m3 == LONG_MIN ? m1 : m3;
    }
};
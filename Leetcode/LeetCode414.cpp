// LeetCode 414 第三大的数
#include <climits>
#include <limits>
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
        set<int, greater<int>> st(nums.begin(), nums.end());
        auto it = st.begin();
        if (st.size() < 3) {
            return *st.begin();
        }
        for (int i = 1; i < 3; ++i) {
            ++it;
        }
        return *it;
    }
};

class Solution3 {
   public:
    int thirdMax(vector<int>& nums) {
        const long INF = numeric_limits<long>::min();
        long m1 = INF, m2 = INF, m3 = INF;
        for (const int& num : nums) {
            if (num == m1 || num == m2 || num == m3) continue;
            if (num > m1) {
                m3 = m2, m2 = m1, m1 = num;
            } else if (num > m2) {
                m3 = m2, m2 = num;
            } else if (num > m3) {
                m3 = num;
            }
        }
        return m3 == INF ? m1 : m3;
    }
};
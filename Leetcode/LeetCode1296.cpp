// LeetCode 1296 划分数组为连续数字的集合

#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) {
            return false;
        }
        map<int, int> cnt;
        for (int num : nums) {
            ++cnt[num];
        }

        int group_count = n / k;
        for (int i = 0; i < group_count; ++i) {
            int first_num = cnt.begin()->first;
            --cnt[first_num];
            if (cnt[first_num] == 0) {
                cnt.erase(first_num);
            }
            for (int j = 1; j < k; ++j) {
                if (cnt.find(first_num + j) == cnt.end()) {
                    return false;
                } else {
                    --cnt[first_num + j];
                    if (cnt[first_num + j] == 0) {
                        cnt.erase(first_num + j);
                    }
                }
            }
        }
        return true;
    }
};
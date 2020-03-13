// 每日一题 多数元素
#include <unordered_map>
#include <vector>
using namespace std;

// 法1: 排序法 28ms
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), target = n / 2, pre = nums[0], cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (cnt > target) return pre;
            if (nums[i] == pre)
                cnt++;
            else
                cnt = 1, pre = nums[i];
        }
        return pre;
    }
};

// 法2: 哈希表法 28ms
class Solution2 {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0, cnt = 0;
        for (int i : nums) {
            mp[i]++;
            if (mp[i] > cnt) ans = i, cnt = mp[i];
        }
        return ans;
    }
};

// 法3: Boyer-Moore投票算法 8ms
class Solution3 {
   public:
    int majorityElement(vector<int>& nums) {
        int candicate = 0, cnt = 0;
        for (int i : nums) {
            if (cnt == 0) candicate = i;
            cnt += (candicate == i ? 1 : -1);
        }
        return candicate;
    }
};

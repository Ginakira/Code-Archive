// LeetCode 80 删除有序数组中的重复项II
#include <map>
#include <vector>
using namespace std;

// 使用map 8ms
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        for (int num : nums) {
            ++mp[num];
        }
        int ind = 0;
        for (auto& [k, v] : mp) {
            for (int i = 0, n = min(2, v); i < n; ++i) {
                nums[ind++] = k;
            }
        }
        return ind;
    }
};

// STL 4ms
class Solution2 {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();

        for (auto it = nums.begin() + 2; it != nums.end();) {
            if ((*(it) == *(it - 1)) && *(it) == *(it - 2)) {
                it = nums.erase(it);
            } else {
                ++it;
            }
        }
        return nums.size();
    }
};

// 逐位移动 8ms
class Solution3 {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int end = n - 1, count = 0;
        for (int i = 2; i <= end;) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                for (int j = i; j < end; ++j) {
                    nums[j] = nums[j + 1];
                }
                --end, ++count;
            } else {
                ++i;
            }
        }
        return n - count;
    }
};

// 快慢指针 4ms
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] == nums[fast]) {
                ++fast;
            } else {
                nums[slow++] = nums[fast++];
            }
        }
        return slow;
    }
};
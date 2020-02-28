// 存在重复元素
#include <unordered_set>
#include <vector>
using namespace std;

// 52ms
// unordered_set内部使用哈希表实现 set使用RB-Tree实现
class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mark;
        for (auto i : nums) {
            if (mark.count(i)) return true;
            mark.insert(i);
        }
        return false;
    }
};

// 44ms 风骚写法
class Solution2 {
   public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() >
               unordered_set<int>(nums.begin(), nums.end()).size();
    }
};

// 28ms 排序后查找相邻元素是否重复
class Solution3 {
   public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};
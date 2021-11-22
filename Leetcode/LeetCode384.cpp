// LeetCode 384 打乱数组

#include <algorithm>
#include <list>
#include <numeric>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 暴力随机
class Solution {
   private:
    vector<int> original_nums;
    vector<int> nums;

   public:
    Solution(vector<int>& nums) {
        time(0);
        this->original_nums = nums;
        this->nums = nums;
    }

    vector<int> reset() {
        copy(original_nums.begin(), original_nums.end(), nums.begin());
        return nums;
    }

    vector<int> shuffle() {
        list<int> alternative_nums(nums.size());
        copy(original_nums.begin(), original_nums.end(),
             alternative_nums.begin());
        for (int i = 0; i < nums.size(); ++i) {
            int offset = rand() % alternative_nums.size();
            auto it = alternative_nums.begin();
            advance(it, offset);
            nums[i] = *it;
            alternative_nums.erase(it);
        }
        return nums;
    }
};

// 标准库
class Solution2 {
   private:
    std::mt19937 engine;
    vector<int> original_nums;
    vector<int> nums;

   public:
    Solution2(vector<int>& nums)
        : engine(std::random_device{}()), original_nums(nums), nums(nums) {}

    vector<int> reset() { return original_nums; }

    vector<int> shuffle() {
        std::shuffle(nums.begin(), nums.end(), engine);
        return nums;
    }
};

// Fisher-Yates 洗牌算法
class Solution3 {
   private:
    vector<int> original_nums;
    vector<int> nums;

   public:
    Solution3(vector<int>& nums) : original_nums(nums), nums(nums) {}

    vector<int> reset() { return original_nums; }

    vector<int> shuffle() {
        for (int i = 0; i < nums.size(); ++i) {
            int offset = rand() % (nums.size() - i);
            swap(nums[offset], nums[nums.size() - i - 1]);
        }
        return nums;
    }
};
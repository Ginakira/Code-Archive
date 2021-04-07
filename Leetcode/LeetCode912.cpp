// LeetCode 912 排序数组
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;

// 快排
class Solution {
   private:
    int partition(vector<int> &nums, int l, int r) {
        int pivot = nums[r];
        int left = l - 1;
        for (int right = l; right < r; ++right) {
            if (nums[right] < pivot) {
                ++left;
                swap(nums[right], nums[left]);
            }
        }
        swap(nums[left + 1], nums[r]);
        return left + 1;
    }

    int randomized_partition(vector<int> &nums, int l, int r) {
        int offset = rand() % (r - l + 1) + l;
        swap(nums[offset], nums[r]);
        return partition(nums, l, r);
    }

    void randomized_quicksort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int pos = randomized_partition(nums, l, r);
        randomized_quicksort(nums, l, pos - 1);
        randomized_quicksort(nums, pos + 1, r);
    }

   public:
    vector<int> sortArray(vector<int> &nums) {
        srand(time(0));
        randomized_quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};
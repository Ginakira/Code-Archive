// LeetCode 2560 打家劫舍IV
#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int minCapability(vector<int>& nums, int k) {
        int lower = *min_element(nums.begin(), nums.end());
        int upper = *max_element(nums.begin(), nums.end());
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            int count = 0;
            bool visited = false;
            for (int x : nums) {
                if (x <= mid && !visited) {
                    ++count;
                    visited = true;
                } else {
                    visited = false;
                }
            }
            if (count >= k) {
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        }
        return lower;
    }
};
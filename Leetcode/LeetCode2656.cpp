// LeetCode 2656 K个元素的最大和

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
    int maximizeSum(vector<int>& nums, int k) {
        int max_num = *std::max_element(nums.begin(), nums.end());
        return (max_num * 2 + k - 1) * k / 2;
    }
};

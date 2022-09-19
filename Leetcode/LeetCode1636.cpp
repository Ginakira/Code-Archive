// LeetCode 1636 按照频率将数组升序排序

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> frequencySort(vector<int>& nums) {
        std::array<int, 201> cnt{0};
        for (int num : nums) {
            ++cnt[num + 100];
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int cnt_a = cnt[a + 100], cnt_b = cnt[b + 100];
            return (cnt_a == cnt_b) ? (a > b) : (cnt_a < cnt_b);
        });
        return nums;
    }
};
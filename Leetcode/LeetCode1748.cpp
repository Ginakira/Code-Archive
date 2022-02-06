// LeetCode 1748 唯一元素的和

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto num : nums) {
            ++cnt[num];
        }

        int sum = 0;
        for (auto [num, count] : cnt) {
            if (count == 1) {
                sum += num;
            }
        }
        return sum;
    }
};
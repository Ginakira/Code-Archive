// LeetCode 1005 K次取反后最大化的数组和

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = -100; i < 0; ++i) {
            int ops = min(k, freq[i]);
            sum += (-i) * 2 * ops;
            k -= ops;
            freq[i] -= ops;
            freq[-i] += ops;
            if (k == 0) {
                break;
            }
        }
        if (k % 2 != 0 && freq[0] == 0) {
            for (int i = 1; i < 100; ++i) {
                if (freq[i] != 0) {
                    sum += -i * 2;
                    --freq[i];
                    ++freq[-i];
                    break;
                }
            }
        }
        return sum;
    }
};
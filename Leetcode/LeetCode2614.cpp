// LeetCode 2614 对角线上的质数

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
    int diagonalPrime(vector<vector<int>>& nums) {
        auto is_prime = [](int num) {
            if (num == 1) {
                return false;
            }
            for (int i = 2; i * i <= num; ++i) {
                if (num % i == 0) {
                    return false;
                }
            }
            return true;
        };
        int max_prime = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (is_prime(nums[i][i])) {
                max_prime = max(max_prime, nums[i][i]);
            }
            if (is_prime(nums[i][n - i - 1])) {
                max_prime = max(max_prime, nums[i][n - i - 1]);
            }
        }
        return max_prime;
    }
};
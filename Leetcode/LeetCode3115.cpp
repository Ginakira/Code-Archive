// LeetCode 3115 质数的最大距离

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
    int maximumPrimeDifference(vector<int>& nums) {
        static unordered_set<int> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                                            29, 31, 37, 41, 43, 47, 53, 59, 61,
                                            67, 71, 73, 79, 83, 89, 97};
        auto is_prime = [&](int num) { return primes.count(num); };
        auto first = std::find_if(nums.begin(), nums.end(), is_prime);
        auto last = std::find_if(nums.rbegin(), nums.rend(), is_prime);
        return std::distance(first, last.base()) - 1;
    }
};
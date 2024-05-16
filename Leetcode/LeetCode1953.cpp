// LeetCode 1953 你可以工作的最大周数

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
    long long numberOfWeeks(vector<int>& milestones) {
        long long longest = *ranges::max_element(milestones);
        long long rest =
            accumulate(milestones.begin(), milestones.end(), 0LL) - longest;
        if (longest <= rest + 1) {
            return longest + rest;
        } else {
            return rest * 2 + 1;
        }
    }
};
// LeetCode 1015 可能被K整除的最小整数

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
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        int remainder = 1 % k, len = 1;
        unordered_set<int> seen;
        seen.insert(remainder);
        while (remainder != 0) {
            remainder = (remainder * 10 + 1) % k;
            ++len;
            if (seen.count(remainder)) {
                return -1;
            }
            seen.insert(remainder);
        }
        return len;
    }
};
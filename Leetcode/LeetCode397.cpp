// LeetCode 397 整数替换

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (!(n & 1)) {
            return integerReplacement(n / 2) + 1;
        }
        return min(integerReplacement(n / 2 + 1), integerReplacement(n / 2)) +
               2;
    }
};
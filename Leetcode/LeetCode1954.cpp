// LeetCode 1954 收集足够苹果的最小花园周长

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
    long long minimumPerimeter(long long neededApples) {
        long long left = 1, right = 100000;
        while (left < right) {
            long long mid = (left + right) / 2;
            if (2 * mid * (mid + 1) * (mid * 2 + 1) >= neededApples) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left * 8;
    }
};
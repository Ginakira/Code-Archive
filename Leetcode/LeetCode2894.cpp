// LeetCode 2894 分类求和并作差

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
    int differenceOfSums(int n, int m) {
        int sum_a = 0, sum_b = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % m != 0) {
                sum_a += i;
            } else {
                sum_b += i;
            }
        }
        return sum_a - sum_b;
    }
};

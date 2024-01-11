// LeetCode 2578 最小和分割

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
    int splitNum(int num) {
        std::string digits = std::to_string(num);
        std::sort(digits.begin(), digits.end());
        int num_a = 0, num_b = 0;
        for (int i = 0; i < digits.size(); ++i) {
            int digit = digits[i] - '0';
            if (i & 1) {
                num_a = num_a * 10 + digit;
            } else {
                num_b = num_b * 10 + digit;
            }
        }
        return num_a + num_b;
    }
};

// LeetCode 3340 检查平衡字符串

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
    bool isBalanced(string num) {
        int odd_sum = 0, even_sum = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (i & 1) {
                odd_sum += num[i] - '0';
            } else {
                even_sum += num[i] - '0';
            }
        }
        return odd_sum == even_sum;
    }
};
// LeetCode 3751 范围内总波动值 I

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
  int totalWaviness(int num1, int num2) {
    int ans = 0;
    for (int i = num1; i <= num2; ++i) {
      string num = to_string(i);
      for (int j = 1; j < num.size() - 1; ++j) {
        if ((num[j] > num[j - 1] && num[j] > num[j + 1]) ||
            (num[j] < num[j - 1] && num[j] < num[j + 1])) {
          ++ans;
        }
      }
    }
    return ans;
  }
};
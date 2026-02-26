// LeetCode 1404 将二进制表示减到 1 的步骤数
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
  int numSteps(string s) {
    int ans = s.size() - 1;
    int carry = 0;
    for (int i = s.size() - 1; i > 0; --i) {
      int sum = s[i] - '0' + carry;
      ans += sum % 2;
      carry = sum > 0;
    }
    return ans + carry;
  }
};
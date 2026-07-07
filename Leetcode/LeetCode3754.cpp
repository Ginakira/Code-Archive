// LeetCode 3754 连接非零数字并乘以其数字和 I

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
  long long sumAndMultiply(int n) {
    if (n == 0) {
      return 0;
    }
    string s = to_string(n);
    int sum = 0;
    s.erase(remove_if(s.begin(), s.end(),
                      [&sum](char c) {
                        sum += c - '0';
                        return c == '0';
                      }),
            s.end());
    return stoll(s) * sum;
  }
};
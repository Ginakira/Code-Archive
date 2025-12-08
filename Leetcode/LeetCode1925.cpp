// LeetCode 1925 统计平方和三元组的数目

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
  int countTriples(int n) {
    int ans = 0;
    for (int a = 1; a <= n; ++a) {
      for (int b = 1; b < a && a * a + b * b <= n * n; ++b) {
        int c2 = a * a + b * b;
        int c = sqrt(c2);
        if (c * c == c2) {
          ++ans;
        }
      }
    }
    return ans * 2;
  }
};
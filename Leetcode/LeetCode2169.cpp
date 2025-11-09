// LeetCode 2169 得到 0 的操作数

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
  int countOperations(int num1, int num2) {
    int cnt = 0;
    while (num2 > 0) {
      cnt += num1 / num2;
      num1 %= num2;
      swap(num1, num2);
    }
    return cnt;
  }
};
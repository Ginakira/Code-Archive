// LeetCode 1323 6 和 9 组成的最大数字

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
  int maximum69Number(int num) {
    std::string s = to_string(num);
    if (auto pos = s.find('6'); pos != string::npos) {
      s[pos] = '9';
    }
    return stoi(s);
  }
};
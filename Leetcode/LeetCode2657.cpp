// LeetCode 2657 找到两个数组的前缀公共数组

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
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    multiset<int> sa, sb;

    auto get_intersection_cnt = [&]() {
      auto ita = sa.begin(), itb = sb.begin();
      int count = 0;
      while (ita != sa.end() && itb != sb.end()) {
        int a = *ita, b = *itb;
        if (a < b) {
          ++ita;
        } else if (a > b) {
          ++itb;
        } else {
          ++count;
          ++ita;
          ++itb;
        }
      }
      return count;
    };

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      sa.emplace(A[i]);
      sb.emplace(B[i]);
      ans[i] = get_intersection_cnt();
    }
    return ans;
  }
};
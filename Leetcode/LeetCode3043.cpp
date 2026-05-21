// LeetCode 3043 最长公共前缀的长度

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
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> st;
    for (int x : arr1) {
      for (; x > 0; x /= 10) {
        st.emplace(x);
      }
    }

    int max_len = 0;
    for (int x : arr2) {
      for (; x > 0 && !st.contains(x); x /= 10) {
      }
      max_len = max(max_len, x);
    }
    return max_len ? to_string(max_len).size() : 0;
  }
};
// LeetCode 3838 带权单词映射

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
  string mapWordWeights(vector<string>& words, vector<int>& weights) {
    string s;
    for (const string& word : words) {
      int sum = 0;
      for (char ch : word) {
        sum = (sum + weights[ch - 'a']) % 26;
      }
      s.push_back('z' - sum);
    }
    return s;
  }
};
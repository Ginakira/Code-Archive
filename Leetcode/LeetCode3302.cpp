// LeetCode 3302 字典序最小的合法序列

class Solution {
 public:
  vector<int> validSequence(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> suffix(n + 1, 0);
    for (int i = n - 1, j = m - 1; i >= 0; --i) {
      if (j >= 0 && word1[i] == word2[j]) {
        --j;
        suffix[i] = suffix[i + 1] + 1;
      } else {
        suffix[i] = suffix[i + 1];
      }
    }
    bool changed = false;
    vector<int> ans;
    for (int i = 0, j = 0; i < n; ++i) {
      if (j == m) {
        break;
      }
      if (word1[i] == word2[j]) {
        ans.emplace_back(i);
        ++j;
      } else if (!changed) {
        if (suffix[i + 1] >= m - (j + 1)) {
          changed = true;
          ans.emplace_back(i);
          ++j;
        }
      }
    }
    return ans.size() == m ? ans : vector<int>{};
  }
};
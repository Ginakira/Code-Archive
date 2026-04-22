// LeetCode 2452 距离字典两次编辑以内的单词

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
  vector<string> twoEditWords(vector<string>& queries,
                              vector<string>& dictionary) {
    unordered_map<int, vector<string>> len_to_words;
    for (const auto& word : dictionary) {
      len_to_words[word.size()].emplace_back(word);
    }
    vector<string> ans;
    auto is_valid = [](const string& a, const string& b) -> bool {
      bool valid = true;
      int tolerance = 2;
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
          if (--tolerance < 0) {
            valid = false;
            break;
          }
        }
      }
      return valid;
    };
    for (const auto& query : queries) {
      if (!len_to_words.count(query.size())) {
        continue;
      }
      for (const auto& word : len_to_words[query.size()]) {
        if (is_valid(query, word)) {
          ans.emplace_back(query);
          break;
        }
      }
    }
    return ans;
  }
};

class Solution2 {
 public:
  vector<string> twoEditWords(vector<string>& queries,
                              vector<string>& dictionary) {
    array<vector<string>, 101> len_to_words{{}};
    for (const auto& word : dictionary) {
      len_to_words[word.size()].emplace_back(word);
    }
    vector<string> ans;
    auto is_valid = [](const string& a, const string& b) -> bool {
      bool valid = true;
      int tolerance = 2;
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
          if (--tolerance < 0) {
            valid = false;
            break;
          }
        }
      }
      return valid;
    };
    for (const auto& query : queries) {
      for (const auto& word : len_to_words[query.size()]) {
        if (is_valid(query, word)) {
          ans.emplace_back(query);
          break;
        }
      }
    }
    return ans;
  }
};
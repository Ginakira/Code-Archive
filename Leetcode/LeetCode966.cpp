// LeetCode 966 元音拼写检查器

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
  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    auto is_vowel = [](char c) {
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    auto to_lower = [](std::string word) {
      ranges::transform(word, word.begin(),
                        [](char ch) { return tolower(ch); });
      return word;
    };

    auto to_vowel_insensitive = [is_vowel](std::string word) {
      ranges::transform(word, word.begin(), [is_vowel](char ch) -> char {
        ch = tolower(ch);
        return is_vowel(ch) ? '*' : ch;
      });
      return word;
    };

    unordered_set<string> dict;
    unordered_map<string, string> dict_case, dict_vowel;
    for (const auto& word : wordlist) {
      dict.emplace(word);
      dict_case.try_emplace(to_lower(word), word);
      dict_vowel.try_emplace(to_vowel_insensitive(word), word);
    }

    dict.reserve(wordlist.size());
    dict_case.reserve(wordlist.size());
    dict_vowel.reserve(wordlist.size());

    vector<string> ans;
    ans.reserve(queries.size());
    for (const auto& query : queries) {
      string s;
      if (dict.count(query)) {
        s = query;
      } else if (string key = to_lower(query); dict_case.count(key)) {
        s = dict_case[key];
      } else if (string key = to_vowel_insensitive(query);
                 dict_vowel.count(key)) {
        s = dict_vowel[key];
      }
      ans.emplace_back(s);
    }
    return ans;
  }
};
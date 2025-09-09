// LeetCode 1733 需要教语言的最小人数

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
  int minimumTeachings(int n, vector<vector<int>>& languages,
                       vector<vector<int>>& friendships) {
    int m = languages.size();
    unordered_set<int> cannot_con;
    for (auto& fs : friendships) {
      int u = fs[0], v = fs[1];
      unordered_map<int, bool> mp;
      bool flag = false;
      for (int lang : languages[u - 1]) {
        mp[lang] = true;
      }
      for (int lang : languages[v - 1]) {
        if (mp[lang]) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        cannot_con.emplace(u - 1);
        cannot_con.emplace(v - 1);
      }
    }
    int max_cnt = 0;
    vector<int> cnt(n + 1, 0);
    for (auto& cc : cannot_con) {
      for (int lang : languages[cc]) {
        ++cnt[lang];
        max_cnt = max(max_cnt, cnt[lang]);
      }
    }
    return cannot_con.size() - max_cnt;
  }
};
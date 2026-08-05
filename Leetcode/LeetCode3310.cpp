// LeetCode 3310 移除可疑的方法

class Solution {
 public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> callees(n);
    vector<int8_t> bad_funcs(n, false);
    for (auto& inv : invocations) {
      int caller = inv[0], callee = inv[1];
      callees[caller].emplace_back(callee);
    }
    auto dfs = [&](this auto& dfs, int cur) {
      if (bad_funcs[cur]) {
        return;
      }
      bad_funcs[cur] = true;
      for (int callee : callees[cur]) {
        dfs(callee);
      }
    };
    dfs(k);

    for (auto& inv : invocations) {
      int caller = inv[0], callee = inv[1];
      if (bad_funcs[callee] && !bad_funcs[caller]) {
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        return ans;
      }
    }

    vector<int> ans;
    ans.reserve(n);
    for (int i = 0; i < n; ++i) {
      if (bad_funcs[i]) {
        continue;
      }
      ans.emplace_back(i);
    }
    return ans;
  }
};
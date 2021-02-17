// 剑指 Offer 38. 字符串的排列
// 回溯 DFS
#include <algorithm>
#include <deque>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// 排序 判断重复
class Solution {
   public:
    vector<string> permutation(string _s) {
        s = _s;
        len = s.size();
        sort(s.begin(), s.end());
        used.resize(len);
        backtrack("");
        return ans;
    }

   private:
    void backtrack(string str) {
        if (str.size() == len) {
            ans.emplace_back(str);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (used[i] == true) continue;
            if (i > 0 && s[i] == s[i - 1] &&
                used[i - 1]) {  // 当前位是重复位且上一个已经用过了 剪枝
                continue;
            }
            used[i] = true;
            backtrack(str + s[i]);
            used[i] = false;
        }
    }

    int len;
    string s;
    vector<string> ans;
    deque<bool> used;
};

// 逐位固定法

class Solution2 {
   public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return ans;
    }

   private:
    void dfs(string s, int pos) {
        if (pos == s.size() - 1) {
            ans.emplace_back(s);
            return;
        }
        unordered_set<char> used;
        for (int i = pos; i < s.size(); ++i) {
            if (used.count(s[i])) continue;
            used.insert(s[i]);
            swap(s[i], s[pos]);  // 固定第pos位
            dfs(s, pos + 1);
            swap(s[i], s[pos]);  // 回溯复原
        }
    }

    vector<string> ans;
};
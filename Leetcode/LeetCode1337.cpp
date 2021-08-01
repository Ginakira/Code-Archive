// LeetCode 1337 矩阵中战斗力最弱的K行

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 排序
class Solution {
   public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        vector<pair<int, int>> save;
        for (int i = 0; i < mat.size(); ++i) {
            int tmp = 0;
            for (int j = 0; j < mat[i].size(); ++j) {
                tmp += mat[i][j];
            }
            pair<int, int> tmp_pair;
            tmp_pair = make_pair(i, tmp);
            save.push_back(tmp_pair);
        }
        sort(save.begin(), save.end(), cmp);
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(save[i].first);
        }
        return ans;
    }
};

// 大顶堆
class Solution2 {
   public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
            cmp);
        for (int i = 0; i < n; ++i) {
            vector<int> &line = mat[i];
            int val = line.rend() - upper_bound(line.rbegin(), line.rend(), 0);
            pair<int, int> pr{val, i};
            if (q.size() < k) {
                q.push(pr);
            } else if (!cmp(q.top(), pr)) {
                q.pop();
                q.push(pr);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.top().second);
            q.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
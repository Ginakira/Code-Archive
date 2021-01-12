// LeetCode 1203 项目管理
#include <queue>
#include <vector>
using namespace std;

// 双重拓扑排序
// 先将组与组之间的依赖关系确定，并对组进行拓扑排序
// 然后顺序遍历拓扑排序后的各组，再将各组负责的项目依次进行拓扑排序
class Solution {
   public:
    // (BFS)拓扑排序 deg为个点入度 graph为各点之间依赖关系 items为待排序的点集
    vector<int> topSort(vector<int> &deg, vector<vector<int>> &graph,
                        vector<int> &items) {
        queue<int> q;
        for (auto &item : items) {
            if (deg[item] == 0) q.push(item);
        }
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (auto &v : graph[u]) {
                if (--deg[v] == 0) q.push(v);
            }
        }
        return ans.size() == items.size() ? ans : vector<int>{};
    }

    vector<int> sortItems(int n, int m, vector<int> &group,
                          vector<vector<int>> &beforeItems) {
        vector<vector<int>> groupItem(n + m);

        // 组间 组内依赖图
        vector<vector<int>> groupGraph(n + m);
        vector<vector<int>> itemGraph(n);

        // 组间 组内入度
        vector<int> groupDegree(n + m, 0);
        vector<int> itemDegree(n, 0);

        vector<int> id;
        for (int i = 0; i < n + m; ++i) {
            id.emplace_back(i);
        }

        int leftId = m;
        // 给group[i] == -1的项分配一个groupId
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = leftId++;
            }
            groupItem[group[i]].emplace_back(i);
        }
        // 依赖关系建图
        for (int i = 0; i < n; ++i) {
            int curGroupId = group[i];
            for (auto &item : beforeItems[i]) {
                int beforeGroupId = group[item];
                if (beforeGroupId == curGroupId) {
                    ++itemDegree[i];
                    itemGraph[item].emplace_back(i);
                } else {
                    ++groupDegree[curGroupId];
                    groupGraph[beforeGroupId].emplace_back(curGroupId);
                }
            }
        }

        // 组间拓扑关系排序
        vector<int> groupTopSort = topSort(groupDegree, groupGraph, id);
        if (groupTopSort.size() == 0) {
            return vector<int>{};
        }
        vector<int> ans;
        // 组内拓扑关系排序
        for (auto &curGroupId : groupTopSort) {
            int size = groupItem[curGroupId].size();
            if (size == 0) continue;
            vector<int> res =
                topSort(itemDegree, itemGraph, groupItem[curGroupId]);
            if (res.size() == 0) {
                return vector<int>{};
            }
            for (auto &item : res) {
                ans.emplace_back(item);
            }
        }
        return ans;
    }
};
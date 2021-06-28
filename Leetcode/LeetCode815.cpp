// LeetCode 815 公交路线
#include <algorithm>
#include <climits>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target) {
            return 0;
        }

        int n = routes.size();
        vector<vector<int>> edge(
            n, vector<int>(n));  // 线路间是否连通（有公共的车站）
        unordered_map<int, vector<int>>
            station_line;  // 存含有这个站点的所有线路
                           // station_line[0]就是0号车站处会经过几线的车
        for (int i = 0; i < n; ++i) {
            for (int site : routes[i]) {
                for (int j : station_line[site]) {  // 建边
                    edge[i][j] = edge[j][i] = true;
                }
                station_line[site].push_back(i);
            }
        }

        // 由于不统计在线路中各站点的轮转次数，所以问题转化成了在多个线路间，从含有起点的线路到含有终点的线路要转几次车，所以上一步我们统计每个线路的公共站点，如果有公共站点则两个线路有一条边

        vector<int> dis(n, -1);
        // dis[i]存储从起点要坐的线路到做到i号线路要经过几次（也就是答案的最少乘坐的公交车数量）
        queue<int> q;
        for (int line : station_line[source]) {
            dis[line] = 1;
            q.push(line);
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int y = 0; y < n; ++y) {
                if (edge[x][y] && dis[y] == -1) {
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
        }

        int ret = INT_MAX;
        for (int line : station_line[target]) {
            if (dis[line] != -1) {
                ret = min(ret, dis[line]);
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};
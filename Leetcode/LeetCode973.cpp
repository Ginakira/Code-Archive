// 973. 最接近原点的 K 个点
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// Solution 1 STL
class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(),
                    [](auto&& a, auto&& b) {
                        return a[0] * a[0] + a[1] * a[1] <
                               b[0] * b[0] + b[1] * b[1];
                    });
        points.resize(K);
        return points;
    }
};

// Solution 2 Priority Queue
class Solution2 {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < K; ++i) {
            q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1],
                      i);
        }

        int n = points.size();
        for (int i = K; i < n; ++i) {
            int dist =
                points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (q.top().first > dist) {
                q.pop();
                q.emplace(dist, i);
            }
        }

        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.emplace_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};
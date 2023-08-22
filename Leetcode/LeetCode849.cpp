// LeetCode 849 到最近的人的最大距离

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
    int maxDistToClosest(vector<int> &seats) {
        size_t n = seats.size();
        auto cal_dis = [&seats](int n, int start, int end, int step) {
            vector<int> dis(n);
            for (int i = start, cnt = n; i != end; i += step) {
                if (seats[i] == 1) {
                    cnt = 0;
                    continue;
                }
                ++cnt;
                dis[i] = cnt;
            }
            return dis;
        };
        auto dis = cal_dis(n, 0, n, 1);
        auto dis_rev = cal_dis(n, n - 1, -1, -1);
        int ans_dis = -1;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                continue;
            }
            ans_dis = max(ans_dis, min(dis[i], dis_rev[i]));
        }
        return ans_dis;
    }
};

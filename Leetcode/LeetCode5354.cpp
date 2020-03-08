// 周赛3题 通知所有员工所需的时间
#include <vector>
using namespace std;

// DFS 超时 32/39组通过
class Solution {
   public:
    int cal_max(int headID, vector<int>& manager, vector<int>& time) {
        int cur_max = 0;
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] == headID) {
                cur_max = max(cur_max, time[i] + cal_max(i, manager, time));
            }
        }
        return cur_max;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        return informTime[headID] + cal_max(headID, manager, informTime);
    }
};

// 自底向上搜寻 + 剪枝（也就是只从最下面的员工开始向上找）
// 与并查集的find操作相仿
class Solution2 {
   public:
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (informTime[i]) continue;
            int tmp = 0, ind = manager[i];
            while (ind != -1) {
                tmp += informTime[ind];
                ind = manager[ind];
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};
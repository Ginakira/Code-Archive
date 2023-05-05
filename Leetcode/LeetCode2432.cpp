// LeetCode 2432 处理任务用时最长的那个任务的员工

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
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans_id = -1, ans_time = -1;
        int pre_time = 0;
        for (auto& log : logs) {
            int id = log[0], time = log[1];
            int time_used = time - pre_time;
            if (time_used > ans_time ||
                (time_used == ans_time && id < ans_id)) {
                ans_time = time_used;
                ans_id = id;
            }
            pre_time = time;
        }
        return ans_id;
    }
};
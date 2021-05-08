// LeetCode 1723 完成所有工作的最短时间
#include <numeric>
#include <vector>
using namespace std;

// 二分 + 回溯
class Solution {
   private:
    bool backtrack(vector<int> &jobs, vector<int> &workloads, int index,
                   int limit) {
        if (index >= jobs.size()) {
            return true;
        }
        int cur_job = jobs[index];
        for (auto &workload : workloads) {
            if (workload + cur_job <= limit) {
                workload += cur_job;
                if (backtrack(jobs, workloads, index + 1, limit)) {
                    return true;
                }
                workload -= cur_job;
            }
            if (workload == 0 || workload + cur_job == limit) {
                break;
            }
        }
        return false;
    }

    bool check(vector<int> &jobs, int k, int limit) {
        vector<int> workloads(k, 0);
        return backtrack(jobs, workloads, 0, limit);
    }

   public:
    int minimumTimeRequired(vector<int> &jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());
        int left = jobs[0], right = accumulate(jobs.begin(), jobs.end(), 0);
        while (left < right) {
            int mid = (left + right) / 2;
            if (check(jobs, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
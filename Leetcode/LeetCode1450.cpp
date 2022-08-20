// LeetCode 1450 在既定时间做作业的学生人数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime,
                    int queryTime) {
        int cnt = 0;
        for (int i = 0; i < startTime.size(); ++i) {
            if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
                ++cnt;
            }
        }
        return cnt;
    }
};

// 差分
class Solution2 {
   public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime,
                    int queryTime) {
        int n = startTime.size();
        int max_time = *max_element(endTime.begin(), endTime.end());
        if (queryTime > max_time) {
            return 0;
        }
        vector<int> diff(max_time + 2, 0);
        for (int i = 0; i < n; ++i) {
            ++diff[startTime[i]];
            --diff[endTime[i] + 1];
        }
        int ans = 0;
        for (int i = 0; i <= queryTime; ++i) {
            ans += diff[i];
        }
        return ans;
    }
};

// 二分
class Solution3 {
   public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime,
                    int queryTime) {
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int start = upper_bound(startTime.begin(), startTime.end(), queryTime) -
                    startTime.begin();
        int end = lower_bound(endTime.begin(), endTime.end(), queryTime) -
                  endTime.begin();
        return start - end;
    }
};
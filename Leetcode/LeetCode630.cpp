// LeetCode 630 课程表II

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
    int scheduleCourse(vector<vector<int>> &courses) {
        std::sort(courses.begin(), courses.end(),
                  [](auto &a, auto &b) { return a[1] < b[1]; });
        std::priority_queue<int> pq;
        int total_time = 0;
        for (auto &course : courses) {
            int dur = course[0], last = course[1];
            if (total_time + dur <= last) {
                pq.push(dur);
                total_time += dur;
            } else if (!pq.empty() && pq.top() > dur) {
                total_time += dur - pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
    }
};

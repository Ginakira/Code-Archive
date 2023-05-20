// LeetCode 2246 判断两个事件是否存在冲突

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
   private:
    int TimeStrToMinutes(string s) {
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));
        return h * 60 + m;
    }

   public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        std::array<pair<int, int>, 2> events{{
            {TimeStrToMinutes(event1[0]), TimeStrToMinutes(event1[1])},
            {TimeStrToMinutes(event2[0]), TimeStrToMinutes(event2[1])},
        }};
        sort(events.begin(), events.end());
        return events[1].first <= events[0].second;
    }
};

class Solution2 {
   public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return !(event1[1] < event2[0] || event2[1] < event1[0]);
    }
};
// LeetCode 729 我的日程安排表 I

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

class MyCalendar {
   private:
    set<tuple<int, int>> schedule;

   public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = schedule.upper_bound({end, 0});
        if (it == schedule.begin() || get<1>(*--it) <= start) {
            schedule.insert({start, end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
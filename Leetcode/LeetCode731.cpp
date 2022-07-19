// LeetCode 731 我的日程安排表II

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MyCalendarTwo {
   private:
    using Schedule = tuple<int, int>;
    vector<Schedule> single_booking;
    vector<Schedule> double_booking;

   public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (auto &[l, r] : double_booking) {
            if (start < r && end > l) {
                return false;
            }
        }
        for (auto &[l, r] : single_booking) {
            if (start < r && end > l) {
                double_booking.emplace_back(max(start, l), min(end, r));
            }
        }
        single_booking.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
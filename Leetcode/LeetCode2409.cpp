// LeetCode 2409 统计共同度过的日子数

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
    static constexpr std::array<int, 12> month_to_days_{
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    auto ParseDateToDay(const string date) {
        int month = std::stoi(date.substr(0, 2)),
            day = std::stoi(date.substr(3, 2));
        int days = 0;
        days = std::accumulate(month_to_days_.begin(),
                               next(month_to_days_.begin(), month - 1), 0) +
               day;
        return days;
    }

   public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int alice_arrive_day = ParseDateToDay(arriveAlice),
            alice_leave_day = ParseDateToDay(leaveAlice);
        int bob_arrive_day = ParseDateToDay(arriveBob),
            bob_leave_day = ParseDateToDay(leaveBob);
        int common_days = min(alice_leave_day, bob_leave_day) -
                          max(alice_arrive_day, bob_arrive_day) + 1;
        return max(common_days, 0);
    }
};
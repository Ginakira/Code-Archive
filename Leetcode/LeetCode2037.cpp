// LeetCode 2037 使每位学生都有座位的最少移动次数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        size_t n = seats.size();
        for (size_t i = 0; i < n; ++i) {
            ans += abs(students[i] - seats[i]);
        }
        return ans;
    }
};
// LeetCode 1700 无法吃午餐的学生数量

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stu_circle_count = count(students.begin(), students.end(), 0);
        int stu_square_count = students.size() - stu_circle_count;
        for (int sandwich : sandwiches) {
            if (sandwich == 0 && stu_circle_count > 0) {
                --stu_circle_count;
            } else if (sandwich == 1 && stu_square_count > 0) {
                --stu_square_count;
            } else {
                return stu_circle_count + stu_square_count;
            }
        }
        return 0;
    }
};
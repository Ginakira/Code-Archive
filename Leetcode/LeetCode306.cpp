// LeetCode 306 累加数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int second_start = 1; second_start < n - 1; ++second_start) {
            if (num[0] == '0' && second_start != 1) {
                break;
            }
            for (int second_end = second_start; second_end < n - 1;
                 ++second_end) {
                if (num[second_start] == '0' && second_end != second_start) {
                    break;
                }
                if (valid(second_start, second_end, num)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool valid(int second_start, int second_end, const string &num) {
        int n = num.size();
        int first_start = 0, first_end = second_start - 1;
        long long first_num =
            stoll(num.substr(first_start, first_end - first_start + 1));
        long long second_num =
            stoll(num.substr(second_start, second_end - second_start + 1));
        while (second_end < n - 1) {
            long long third_num = first_num + second_num;
            string third_sum = to_string(third_num);
            string third_str = num.substr(second_end + 1, third_sum.size());
            if (third_sum != third_str) {
                return false;
            }
            first_num = second_num;
            second_num = third_num;
            first_start = second_start;
            first_end = second_end;
            second_start = second_end + 1;
            second_end = second_start + third_sum.size() - 1;
        }
        return true;
    }
};
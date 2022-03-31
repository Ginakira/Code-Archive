// LeetCode 728 自除数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> selfDividingNumbers(int left, int right) {
        auto check = [](int num) {
            if (num == 0) return false;
            int cur = num;
            while (cur) {
                if (cur % 10 == 0) return false;
                if (num % (cur % 10) != 0) {
                    return false;
                }
                cur /= 10;
            }
            return true;
        };

        vector<int> result;
        for (int i = left; i <= right; ++i) {
            if (check(i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};
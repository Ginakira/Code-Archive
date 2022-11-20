// LeetCode 799 香槟塔

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur_row{static_cast<double>(poured)};
        for (int i = 1; i <= query_row; ++i) {
            vector<double> next_row(i + 1, 0.0);
            for (int j = 0; j < i; ++j) {
                if (cur_row[j] > 1) {
                    double half_overflow = (cur_row[j] - 1) / 2;
                    next_row[j] += half_overflow;
                    next_row[j + 1] += half_overflow;
                }
            }
            cur_row = move(next_row);
        }
        return min(1.0, cur_row[query_glass]);
    }
};
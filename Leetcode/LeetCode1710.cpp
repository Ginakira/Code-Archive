// LeetCode 1710 卡车上的最大单元数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        int unit_sum = 0, box_sum = 0;
        sort(boxTypes.begin(), boxTypes.end(),
             [](auto &a, auto &b) { return a[1] > b[1]; });
        for (auto &box_type : boxTypes) {
            int box_cnt = min(truckSize - box_sum, box_type[0]);
            if (box_cnt == 0) {
                break;
            }
            unit_sum += box_cnt * box_type[1];
            box_sum += box_cnt;
        }
        return unit_sum;
    }
};
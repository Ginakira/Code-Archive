// LeetCode 1619 删除某些元素后的数组均值

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), drop_num = int(n * 0.05);
        return accumulate(arr.begin() + drop_num, arr.begin() + n - drop_num,
                          0) /
               double(n - drop_num * 2);
    }
};
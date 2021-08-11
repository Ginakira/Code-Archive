// 剑指 Offer 17. 打印从1到最大的n位数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> printNumbers(int n) {
        int max_val = stoi(string(n, '9'));
        vector<int> result(max_val);
        for (int i = 1; i <= max_val; ++i) {
            result[i - 1] = i;
        }
        return result;
    }
};
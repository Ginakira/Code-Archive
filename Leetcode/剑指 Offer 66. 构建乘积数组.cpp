// 剑指 Offer 66. 构建乘积数组
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; ++i) {
            left[i] = a[i - 1] * left[i - 1];
            right[n - i - 1] = a[n - i] * right[n - i];
        }
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = left[i] * right[i];
        }
        return result;
    }
};
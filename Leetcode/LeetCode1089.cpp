// LeetCode 1089 复写零

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 额外空间
class Solution {
   public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> res;
        size_t ind = 0;
        while (res.size() < arr.size()) {
            res.emplace_back(arr[ind]);
            if (arr[ind] == 0 && res.size() < arr.size()) {
                res.emplace_back(0);
            }
            ++ind;
        }
        arr.swap(res);
    }
};
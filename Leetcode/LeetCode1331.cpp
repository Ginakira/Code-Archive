// LeetCode 1331 数字序号转换

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        vector<int> arr_ind;
        for (int i = 0; i < arr.size(); ++i) {
            arr_ind.emplace_back(i);
        }
        sort(arr_ind.begin(), arr_ind.end(),
             [&arr](auto &a, auto &b) { return arr[a] < arr[b]; });
        for (int i = 0, rank = 1, last = 0; i < arr_ind.size(); ++i) {
            if (i > 0 && arr[arr_ind[i]] != last) {
                ++rank;
            }
            last = arr[arr_ind[i]];
            arr[arr_ind[i]] = rank;
        }
        return arr;
    }
};
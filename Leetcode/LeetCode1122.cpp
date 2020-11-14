// LeetCode 1122 数组的相对排序
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> pos;
        for (int i = 0, n = arr2.size(); i < n; ++i) {
            pos[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int a, int b) -> bool {
            if (pos.count(a)) {
                return pos.count(b) ? pos[a] < pos[b] : true;
            } else {
                return pos.count(b) ? false : a < b;
            }
        });
        return arr1;
    }
};
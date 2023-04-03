// LeetCode 1053 交换一次的先前排列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        size_t n = arr.size();
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] <= arr[i + 1]) {
                continue;
            }
            int j = n - 1;
            while (arr[j] >= arr[i] || arr[j] == arr[j - 1]) {
                --j;
            }
            swap(arr[i], arr[j]);
            break;
        }
        return arr;
    }
};
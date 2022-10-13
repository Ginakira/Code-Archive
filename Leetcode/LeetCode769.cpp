// LeetCode 769 最多能完成排序的块

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_num = -1, ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            max_num = max(max_num, arr[i]);
            if (max_num == i) {
                ++ans;
            }
        }
        return ans;
    }
};
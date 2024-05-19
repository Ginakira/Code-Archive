// LeetCode 1535 找出数组游戏的赢家

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        int ind = 0;
        for (int i = 1; i < n && cnt < k; ++i) {
            if (arr[ind] > arr[i]) {
                ++cnt;
            } else {
                cnt = 1;
                ind = i;
            }
        }
        return arr[ind];
    }
};
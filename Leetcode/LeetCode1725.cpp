// LeetCode 1735 可以形成最大正方形的矩形数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max_k = 0;
        unordered_map<int, int> cnt;
        for (auto& rectangle : rectangles) {
            int k = min(rectangle[0], rectangle[1]);
            ++cnt[k];
            max_k = max(max_k, k);
        }
        return cnt[max_k];
    }
};
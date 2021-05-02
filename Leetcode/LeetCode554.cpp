// LeetCode 554 砖墙
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> edge_count;
        for (auto &width : wall) {
            int n = width.size(), sum = 0;
            for (int i = 0; i < n - 1; ++i) {
                sum += width[i];
                ++edge_count[sum];
            }
        }
        int max_edge_count =
            edge_count.empty()
                ? 0
                : max_element(edge_count.begin(), edge_count.end(),
                              [](const auto &a, const auto &b) {
                                  return a.second < b.second;
                              })
                      ->second;
        return wall.size() - max_edge_count;
    }
};
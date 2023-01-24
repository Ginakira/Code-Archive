// LeetCode 1828 统计一个圆中点的数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> countPoints(vector<vector<int>>& points,
                            vector<vector<int>>& queries) {
        vector<int> answer;
        answer.reserve(queries.size());
        for (auto& query : queries) {
            int cx = query[0], cy = query[1], cr = query[2];
            answer.emplace_back(0);
            for (auto& point : points) {
                int x = point[0], y = point[1];
                if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= cr * cr) {
                    ++answer.back();
                }
            }
        }
        return answer;
    }
};
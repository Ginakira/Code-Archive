// LeetCode 1436 旅行终点站

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string destCity(vector<vector<string>> &paths) {
        unordered_set<string> us;
        for (auto &path : paths) {
            us.insert(path[0]);
        }
        for (auto &path : paths) {
            if (!us.count(path[1])) {
                return path[1];
            }
        }
        return {};
    }
};
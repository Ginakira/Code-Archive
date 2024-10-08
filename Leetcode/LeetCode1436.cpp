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

class Solution2 {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, tuple<int, int>> degs;
        for (auto &path : paths) {
            const auto &u = path[0], v = path[1];
            ++get<0>(degs[v]);
            ++get<1>(degs[u]);
        }
        return ranges::find_if(degs, [](const auto &deg) {
            return get<1>(deg.second) == 0;
        })->first;
    }
};
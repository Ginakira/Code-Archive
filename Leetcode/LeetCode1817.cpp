// LeetCode 1817 查找用户活跃分钟数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
        vector<int> result(k, 0);
        unordered_map<int, unordered_set<int>> id_to_active;
        for (auto &log : logs) {
            id_to_active[log[0]].insert(log[1]);
        }
        for (auto &[_, activce_minutes] : id_to_active) {
            ++result[activce_minutes.size() - 1];
        }
        return result;
    }
};
// LeetCode 1792 最大的平均通过率

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    struct Ratio {
        int pass;
        int total;
        bool operator<(const Ratio &rhs) const {
            return (long long)(rhs.total + 1) * rhs.total * (total - pass) <
                   (long long)(total + 1) * total * (rhs.total - rhs.pass);
        }
    };

   public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
        priority_queue<Ratio> q;
        for (auto &cl : classes) {
            q.push({cl[0], cl[1]});
        }
        for (int i = 0; i < extraStudents; ++i) {
            auto [pass, total] = q.top();
            q.pop();
            q.push({pass + 1, total + 1});
        }
        double res = 0;
        for (int i = 0; i < classes.size(); ++i) {
            auto [pass, total] = q.top();
            q.pop();
            res += 1.0 * pass / total;
        }
        return res / classes.size();
    }
};
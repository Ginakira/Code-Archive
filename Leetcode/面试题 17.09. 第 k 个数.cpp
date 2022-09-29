// 面试题 17.09. 第 k 个数

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int getKthMagicNumber(int k) {
        priority_queue<long, vector<long>, greater<long>> q;
        unordered_set<long> seen;
        array<int, 3> factors{3, 5, 7};

        q.push(1);
        seen.insert(1);
        int ans = 1;
        for (int _ = 0; _ < k; ++_) {
            ans = q.top();
            q.pop();
            for (auto &factor : factors) {
                long num = 1L * ans * factor;
                if (!seen.count(num)) {
                    q.push(num);
                    seen.insert(num);
                }
            }
        }
        return ans;
    }
};
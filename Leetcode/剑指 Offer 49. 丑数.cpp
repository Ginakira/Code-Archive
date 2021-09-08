// 剑指 Offer 49. 丑数
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n) {
        const vector<int> factors = {2, 3, 5};
        unordered_set<long> seen = {1};
        priority_queue<long, vector<long>, greater<long>> nums;
        nums.push(1);
        int ugly = 0;
        for (int i = 0; i < n; ++i) {
            long current = nums.top();
            nums.pop();
            ugly = (int)current;
            for (const int &factor : factors) {
                long next_num = current * factor;
                if (seen.count(next_num)) continue;
                nums.push(next_num);
                seen.insert(next_num);
            }
        }
        return ugly;
    }
};
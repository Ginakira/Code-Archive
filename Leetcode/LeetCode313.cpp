// LeetCode 313 超级丑数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> pq;

        seen.insert(1);
        pq.push(1);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            long num = pq.top();
            pq.pop();
            ans = (int)num;
            for (const int& prime : primes) {
                long new_num = num * prime;
                if (seen.count(new_num) == 0) {
                    pq.push(new_num);
                    seen.insert(new_num);
                }
            }
        }
        return ans;
    }
};
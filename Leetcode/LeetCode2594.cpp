// LeetCode 2594 修车的最少时间

#include <algorithm>
#include <array>
#include <cmath>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    using LL = long long;
    long long repairCars(vector<int>& ranks, int cars) {
        LL l = 1, r = 1LL * ranks[0] * cars * cars;
        auto check = [&](LL t) {
            LL cnt = 0;
            for (auto r : ranks) {
                cnt += sqrt(t / r);
            }
            return cnt >= cars;
        };
        while (l < r) {
            LL mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
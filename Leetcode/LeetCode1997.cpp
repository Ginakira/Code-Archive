// LeetCode 1997 访问完所有房间的第一天

#include <algorithm>
#include <array>
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
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<long long> f(n);
        constexpr int MOD = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            f[i] =
                (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1 + MOD) % MOD;
        }
        return f[n - 1];
    }
};
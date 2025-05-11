// LeetCode 2094 找出3位偶数

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
    vector<int> findEvenNumbers(vector<int>& digits) {
        array<int, 10> cnt{{0}};
        for (int d : digits) {
            ++cnt[d];
        }
        vector<int> ans;
        for (int i = 100; i < 1000; i += 2) {
            array<int, 10> temp_cnt{{0}};
            bool ok = true;
            for (int x = i; x > 0; x /= 10) {
                int d = x % 10;
                if (++temp_cnt[d] > cnt[d]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
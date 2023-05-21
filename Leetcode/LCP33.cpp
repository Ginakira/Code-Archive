// LCP 33 蓄水

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
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int ans = 0x3f3f3f3f;
        int max_cap = *max_element(vat.begin(), vat.end());
        if (max_cap == 0) {
            return 0;
        }
        int n = bucket.size();
        for (int store_cnt = 1; store_cnt <= max_cap; ++store_cnt) {
            int increase_cnt_sum = 0;
            for (int i = 0; i < n; ++i) {
                int increase_cnt =
                    max(0, (vat[i] + store_cnt - 1) / store_cnt - bucket[i]);
                increase_cnt_sum += increase_cnt;
            }
            ans = min(ans, increase_cnt_sum + store_cnt);
        }
        return ans;
    }
};
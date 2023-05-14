// LeetCode 1054 距离相等的条形码

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
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> code_to_cnt;
        for (auto barcode : barcodes) {
            ++code_to_cnt[barcode];
        }
        priority_queue<pair<int, int>> pq;
        for (auto& [code, cnt] : code_to_cnt) {
            pq.emplace(cnt, code);
        }
        vector<int> ans;
        while (!pq.empty()) {
            auto [cnt_1, code_1] = pq.top();
            pq.pop();
            if (ans.empty() || ans.back() != code_1) {
                ans.emplace_back(code_1);
                if (cnt_1 > 1) {
                    pq.emplace(cnt_1 - 1, code_1);
                }
            } else {
                auto [cnt_2, code_2] = pq.top();
                pq.pop();
                ans.emplace_back(code_2);
                if (cnt_2 > 1) {
                    pq.emplace(cnt_2 - 1, code_2);
                }
                pq.emplace(cnt_1, code_1);
            }
        }
        return ans;
    }
};
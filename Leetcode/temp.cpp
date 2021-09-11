#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        vector<int> odd, even;
        for (const int& card : cards) {
            if (card & 1) {
                odd.push_back(card);
            } else {
                even.push_back(card);
            }
        }
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());

        for (int i = 1; i < odd.size(); ++i) {
            odd[i] += odd[i - 1];
        }
        for (int i = 1; i < even.size(); ++i) {
            even[i] += even[i - 1];
        }

        int max_ans = 0;
        for (int odd_len = 0; odd_len <= cnt; odd_len += 2) {
            int even_len = cnt - odd_len;
            if (odd_len > odd.size() || even_len > even.size()) {
                continue;
            }
            int sum = 0;
            if (odd_len > 0) {
                sum += odd[odd_len - 1];
            }
            if (even_len > 0) {
                sum += even[even_len - 1];
            }
            max_ans = max(max_ans, sum);
        }
        return max_ans;
    }
};

int main() {
    Solution s;
    vector<int> vec{1, 2, 8, 9};
    s.maxmiumScore(vec, 3);
    return 0;
}
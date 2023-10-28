// LeetCode 2558 从数量最多的堆取走礼物

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
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q(gifts.begin(), gifts.end());
        for (int i = 0; i < k; ++i) {
            int gift = q.top();
            q.pop();
            q.emplace(floor(sqrt(gift)));
        }
        long long sum = 0;
        while (!q.empty()) {
            sum += q.top();
            q.pop();
        }
        return sum;
    }
};
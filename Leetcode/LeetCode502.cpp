// LeetCode 502 IPO

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<tuple<int, int>> vec;
        for (int i = 0; i < n; ++i) {
            vec.emplace_back(capital[i], profits[i]);
        }
        sort(vec.begin(), vec.end());

        int ind = 0;
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < k; ++i) {
            while (ind < n && get<0>(vec[ind]) <= w) {
                q.push(get<1>(vec[ind]));
                ++ind;
            }
            if (q.empty()) {
                break;
            }
            int profit = q.top();
            q.pop();
            w += profit;
        }
        return w;
    }
};
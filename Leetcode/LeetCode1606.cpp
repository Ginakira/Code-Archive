// LeetCode 1606 找到处理最多请求的服务器

#include <algorithm>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> requests(k);
        for (int i = 0; i < arrival.size(); ++i) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) {
                continue;
            }
            auto it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin();
            }
            ++requests[*it];
            busy.emplace(arrival[i] + load[i], *it);
            available.erase(it);
        }

        vector<int> result;
        int max_requests = *max_element(requests.begin(), requests.end());
        for (int i = 0; i < k; ++i) {
            if (requests[i] == max_requests) {
                result.push_back(i);
            }
        }
        return result;
    }
};
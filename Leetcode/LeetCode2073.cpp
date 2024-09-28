// LeetCode 2073 买票需要的时间

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
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int n = tickets.size();
        for (int i = 0;; ++i) {
            i %= n;
            if (tickets[i] == 0) {
                continue;
            }
            ++time;
            --tickets[i];
            if (i == k && tickets[i] == 0) {
                break;
            }
        }
        return time;
    }
};
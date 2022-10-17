// LeetCode 904 水果成篮

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, n = fruits.size();
        int max_len = 0;
        unordered_map<int, int> seen;
        while (right < n) {
            ++seen[fruits[right]];
            while (seen.size() > 2) {
                auto it = seen.find(fruits[left]);
                --it->second;
                if (it->second == 0) {
                    seen.erase(it);
                }
                ++left;
            }
            max_len = max(max_len, right - left + 1);
            ++right;
        }
        return max_len;
    }
};
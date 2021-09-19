// LeetCode 670 最大交换

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int max_ind = -1;
            for (int j = i + 1; j < n; ++j) {
                if (s[j] > s[i]) {
                    if (max_ind == -1 || s[max_ind] <= s[j]) {
                        max_ind = max(max_ind, j);
                    }
                }
            }
            if (max_ind != -1) {
                swap(s[i], s[max_ind]);
                return stoi(s);
            }
        }
        return num;
    }
};
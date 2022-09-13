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

class Solution2 {
   public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int ind_a = 0, ind_b = 0;
        int max_ind = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] > s[max_ind]) {
                max_ind = i;
            } else if (s[i] < s[max_ind]) {
                ind_a = i;
                ind_b = max_ind;
            }
        }
        if (ind_b > 0) {
            swap(s[ind_a], s[ind_b]);
            return stoi(s);
        } else {
            return num;
        }
    }
};
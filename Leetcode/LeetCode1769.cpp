// LeetCode 1769 移动所有球到每个盒子所需的最小操作数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> results(n, 0);
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if (boxes[j] == '1') {
                    sum += abs(i - j);
                }
            }
            results[i] = sum;
        }
        return results;
    }
};

class Solution2 {
   public:
    vector<int> minOperations(string boxes) {
        int left = boxes[0] - '0', right = 0, ops = 0;
        int n = boxes.size();
        for (int i = 1; i < n; ++i) {
            if (boxes[i] == '1') {
                ++right;
                ops += i;
            }
        }
        vector<int> results(n);
        results[0] = ops;
        for (int i = 1; i < n; ++i) {
            ops += left - right;
            if (boxes[i] == '1') {
                ++left;
                --right;
            }
            results[i] = ops;
        }
        return results;
    }
};
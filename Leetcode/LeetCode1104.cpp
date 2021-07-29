// LeetCode 1104 二叉树寻路

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int get_reverse_label(int label, int row) {
        return (1 << (row - 1)) + (1 << row) - 1 - label;
    }

   public:
    vector<int> pathInZigZagTree(int label) {
        int row = 1, row_start = 1;
        while (row_start * 2 <= label) {
            ++row;
            row_start <<= 1;
        }

        if (row % 2 == 0) {
            label = get_reverse_label(label, row);
        }

        vector<int> result;
        while (row > 0) {
            if (row % 2 == 0) {
                result.push_back(get_reverse_label(label, row));
            } else {
                result.push_back(label);
            }
            --row;
            label >>= 1;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
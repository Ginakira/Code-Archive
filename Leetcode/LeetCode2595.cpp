// LeetCode 2595 奇偶位数

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
    vector<int> evenOddBit(int n) {
        int idx = 0;
        int even = 0, odd = 0;
        while (n) {
            if (n & 1) {
                if (idx & 1) {
                    ++odd;
                } else {
                    ++even;
                }
            }
            ++idx;
            n >>= 1;
        }
        return {even, odd};
    }
};
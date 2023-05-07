// LeetCode 1419 数青蛙

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
    int minNumberOfFrogs(string croakOfFrogs) {
        if (croakOfFrogs.size() % 5 != 0) {
            return -1;
        }

        int ans = 0, frog_num = 0;
        array<int, 4> cnt{{0}};
        unordered_map<char, int> mp{
            {'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        for (char ch : croakOfFrogs) {
            int ind = mp[ch];
            if (ind == 0) {
                ++cnt[ind];
                ++frog_num;
                if (frog_num > ans) {
                    ans = frog_num;
                }
            } else {
                if (cnt[ind - 1] == 0) {
                    return -1;
                }
                --cnt[ind - 1];
                if (ind == 4) {
                    --frog_num;
                } else {
                    ++cnt[ind];
                }
            }
        }
        return frog_num == 0 ? ans : -1;
    }
};
// LeetCode 454 四数相加II
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                     vector<int>& D) {
        unordered_map<int, int> mp;
        for (const int& a : A) {
            for (const int& b : B) {
                ++mp[a + b];
            }
        }
        int ans = 0;
        for (const int& c : C) {
            for (const int& d : D) {
                if (mp.find(-(c + d)) != mp.end()) {
                    ans += mp[-(c + d)];
                }
            }
        }
        return ans;
    }
};
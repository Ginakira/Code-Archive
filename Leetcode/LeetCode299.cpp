// LeetCode 299 猜数字游戏

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int n = secret.size();
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
                secret[i] = guess[i] = 0;
            }
        }
        unordered_map<char, int> mp;
        for (char c : secret) {
            if (c == 0) continue;
            mp[c]++;
        }
        for (char c : guess) {
            if (c == 0) continue;
            if (mp[c] > 0) {
                --mp[c];
                ++cows;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
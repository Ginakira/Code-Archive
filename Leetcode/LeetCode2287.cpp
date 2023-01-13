// LeetCode 2287 重排字符形成目标字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> source_mp, target_mp;
        for (char ch : s) {
            ++source_mp[ch];
        }
        for (char ch : target) {
            ++target_mp[ch];
        }

        int max_copies = std::numeric_limits<int>::max();
        for (auto &[ch, cnt] : target_mp) {
            max_copies = min(max_copies, source_mp[ch] / cnt);
        }
        return max_copies;
    }
};
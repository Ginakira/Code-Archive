// LeetCode 567 字符串的排列
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int n = s2.size(), window_size = s1.size();
        vector<int> freq(26, 0), count(26, 0);
        for (int i = 0; i < window_size; ++i) {
            freq[s1[i] - 'a']++;
            count[s2[i] - 'a']++;
        }
        for (int i = window_size; i < n; ++i) {
            if (count == freq) {
                return true;
            }
            ++count[s2[i] - 'a'];
            --count[s2[i - window_size] - 'a'];
        }
        return count == freq;
    }
};
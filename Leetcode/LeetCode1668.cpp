// LeetCode 1668 最大重复字字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxRepeating(string sequence, string word) {
        string s = word;
        int cnt = 0;
        while (sequence.find(s) != string::npos) {
            s += word;
            cnt++;
        }
        return cnt;
    }
};
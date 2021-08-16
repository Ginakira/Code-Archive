// LeetCode 5843 作为子字符串出现在单词中的字符串数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (string& pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                ++count;
            }
        }
        return count;
    }
};
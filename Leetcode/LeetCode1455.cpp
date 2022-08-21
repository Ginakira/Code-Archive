// LeetCode 1455 检查单词是否为句中其他单词的前缀

#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int ind = 1;
        while (ss >> word) {
            if (word.find(searchWord) == 0) {
                return ind;
            }
            ++ind;
        }
        return -1;
    }
};
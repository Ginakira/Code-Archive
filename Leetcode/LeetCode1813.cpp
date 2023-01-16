// LeetCode 1813 句子相似性 III
#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1), ss2(sentence2);
        vector<string> words1, words2;
        string str;
        while (ss1 >> str) {
            words1.emplace_back(str);
        }
        while (ss2 >> str) {
            words2.emplace_back(str);
        }
        int n1 = words1.size(), n2 = words2.size();
        int i = 0, j = 0;
        // Find longest common prefix len
        while (i < n1 && i < n2 && words1[i] == words2[i]) {
            ++i;
        }
        // Find logest common suffix len
        while (j < n1 - i && j < n2 - i &&
               words1[n1 - j - 1] == words2[n2 - j - 1]) {
            ++j;
        }
        return i + j == min(n1, n2);
    }
};
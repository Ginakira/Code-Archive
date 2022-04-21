// LeetCode 824 山羊拉丁文

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
   private:
    inline bool is_vowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

   public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word, ans, cur_suffix;
        while (ss >> word) {
            cur_suffix.push_back('a');
            if (!is_vowel(word[0])) {
                word = word.substr(1) + word[0];
            }
            word += "ma";
            word += cur_suffix;
            ans += word;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};
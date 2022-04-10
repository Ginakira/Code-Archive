// LeetCode 804 唯一摩尔斯密码词

#include <algorithm>
#include <array>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    static constexpr array<const char *, 26> morse_code_table{
        ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

   public:
    int uniqueMorseRepresentations(vector<string> &words) {
        set<string> st;
        for (const auto &word : words) {
            string word_morse;
            for (auto &ch : word) {
                word_morse += morse_code_table[ch - 'a'];
            }
            st.insert(word_morse);
        }
        return st.size();
    }
};
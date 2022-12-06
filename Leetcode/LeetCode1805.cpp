// LeetCode 1805 字符串中不同整数的数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int numDifferentIntegers(string word) {
        word.push_back('-');
        unordered_set<string> st;
        string cur = "";
        for (char ch : word) {
            if (isdigit(ch)) {
                if (cur == "0") {
                    cur = ch;
                } else {
                    cur.push_back(ch);
                }
            } else {
                if (!cur.empty()) {
                    st.insert(cur);
                }
                cur.clear();
            }
        }
        return st.size();
    }
};
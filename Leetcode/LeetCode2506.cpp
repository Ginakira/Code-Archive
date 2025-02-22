// LeetCode 2506 统计相似字符串对的数目

#include <algorithm>
#include <array>
#include <bitset>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int similarPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();
        auto cnt_word = [](const string& word, std::unordered_set<char>& cnt) {
            for (char ch : word) {
                cnt.emplace(ch);
            }
        };
        for (int i = 0; i < n; ++i) {
            std::unordered_set<char> cnt_a;
            cnt_word(words[i], cnt_a);
            for (int j = i + 1; j < n; ++j) {
                std::unordered_set<char> cnt_b;
                cnt_word(words[j], cnt_b);
                if (cnt_a == cnt_b) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

class Solution2 {
   public:
    int similarPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();
        std::vector<std::bitset<26>> marks(n);
        for (int i = 0; i < n; ++i) {
            for (char ch : words[i]) {
                marks[i].set(ch - 'a');
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (marks[i] == marks[j]) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

class Solution3 {
   public:
    int similarPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();
        std::unordered_map<std::bitset<26>, int> marks;
        for (int i = 0; i < n; ++i) {
            std::bitset<26> mark;
            for (char ch : words[i]) {
                mark.set(ch - 'a');
            }
            cnt += marks[mark];
            ++marks[mark];
        }
        return cnt;
    }
};
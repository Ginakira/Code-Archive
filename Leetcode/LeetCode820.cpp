// 每日一题 单词的压缩编码
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 解法1:去重 + 保存后缀
class Solution {
   public:
    int minimumLengthEncoding(vector<string> &words) {
        unordered_set<string> suffix(words.begin(), words.end());
        for (const string &word : words) {
            int n = word.length();
            for (int i = 1; i < n; ++i) {
                suffix.erase(word.substr(i));
            }
        }
        int ans = 0;
        for (const string &word : suffix) {
            ans += word.length() + 1;
        }
        return ans;
    }
};

// 解法2: 倒序存入Trie字典树 各叶子节点高度加1再加和即为答案 与解法1思想一致
class TrieNode {
    TrieNode *children[26];

   public:
    int count;
    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = NULL;
        count = 0;
    }
    TrieNode *get(char c) {
        if (children[c - 'a'] == NULL) {
            children[c - 'a'] = new TrieNode();
            count++;
        }
        return children[c - 'a'];
    }
};

class Solution2 {
   public:
    int minimumLengthEncoding(vector<string> &words) {
        TrieNode *trie = new TrieNode();
        unordered_map<TrieNode *, int> nodes;

        int n = words.size();
        for (int i = 0; i < n; ++i) {
            string word = words[i];
            TrieNode *cur = trie;
            for (int j = word.length() - 1; j >= 0; --j) {
                cur = cur->get(word[i]);
            }
            nodes[cur] = i;
        }

        int ans = 0;
        for (auto &[node, index] : nodes) {
            if (node->count == 0) {
                ans += words[index].length() + 1;
            }
        }
        return ans;
    }
};
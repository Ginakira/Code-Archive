// LeetCode 211 添加与搜索单词 - 数据结构设计
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TrieNode {
   public:
    TrieNode(int _c) : c(_c) {}
    friend class WordDictionary;

   private:
    char c;
    bool isWord = false;
    unordered_map<char, TrieNode *> child;
};

class WordDictionary {
   public:
    WordDictionary() { root = new TrieNode('/'); }

    void addWord(string word) {
        TrieNode *p = root;
        for (const auto &c : word) {
            if (p->child.find(c) != p->child.end()) {
                p = p->child[c];
            } else {
                TrieNode *node = new TrieNode(c);
                p->child[c] = node;
                p = node;
            }
        }
        p->isWord = true;
        return;
    }

    bool search(string word) { return searchHelper(word, 0, root); }

    bool searchHelper(string word, int pos, TrieNode *root) {
        if (pos == word.size()) return root->isWord;
        char c = word[pos];
        if (c == '.') {
            for (const auto &[_, childNode] : root->child) {
                if (searchHelper(word, pos + 1, childNode)) {
                    return true;
                }
            }
        }
        if (root->child.find(c) == root->child.end()) {
            return false;
        }
        return searchHelper(word, pos + 1, root->child[c]);
    }

   private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
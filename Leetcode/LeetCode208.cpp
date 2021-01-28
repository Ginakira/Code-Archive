// LeetCode 208 实现Trie（前缀树）
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class TrieNode {
   public:
    TrieNode(char _c) : c(_c) {}
    friend class Trie;

   private:
    char c;
    bool isWord = false;
    unordered_map<char, TrieNode *> child;
};

class Trie {
   public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode('/')) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *result = find(word);
        if (result == nullptr || result->isWord == false) {
            return false;
        }
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        TrieNode *result = find(prefix);
        if (result == nullptr) {
            return false;
        }
        return true;
    }

    TrieNode *find(string word) {
        TrieNode *p = root;
        for (const auto &c : word) {
            if (p->child.find(c) != p->child.end()) {
                p = p->child[c];
            } else {
                return nullptr;
            }
        }
        return p;
    }

   private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
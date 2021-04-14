// LeetCode 208 实现Trie（前缀树）
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Trie {
   private:
    class TrieNode {
       public:
        TrieNode(char c) : c(c) {}
        char c;
        bool is_word = false;
        unordered_map<char, TrieNode *> children;
    };

    TrieNode *root;

    TrieNode *find(string &word) {
        TrieNode *current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return nullptr;
            }
            current = current->children[c];
        }
        return current;
    }

   public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode('='); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode(c);
            }
            current = current->children[c];
        }
        current->is_word = true;
        return;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *result = find(word);
        return result != nullptr ? result->is_word : false;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        TrieNode *result = find(prefix);
        return result != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
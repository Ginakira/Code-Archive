// LeetCode 648 单词替换
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;

// 前缀树（字典树）
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
    Trie() { this->root = new TrieNode('/'); }

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

    string search(string word) {
        TrieNode *p = root;
        string ret = "";
        for (const auto &c : word) {
            if (p->isWord) break;
            if (p->child.find(c) == p->child.end()) {
                return word;
            }
            ret.push_back(c);
            p = p->child[c];
        }
        return ret;
    }

   private:
    TrieNode *root;
};

class Solution {
   public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        Trie trie;
        for (const auto &word : dictionary) {
            trie.insert(word);
        }

        stringstream ss(sentence);
        string word, ret;
        while (ss >> word) {
            word = trie.search(word);
            ret += word;
            ret += " ";
        }
        ret.erase(ret.size() - 1);
        return ret;
    }
};
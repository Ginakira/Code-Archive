#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
   private:
    class TrieNode {
       public:
        char _ch;
        bool _is_word = false;
        vector<TrieNode *> _children;

        TrieNode(char ch, bool is_word) : _ch(ch), _is_word(is_word) {
            _children.resize(26, nullptr);
        }
    };

   public:
    Trie() { _root = new TrieNode('#', false); }

    void add(const string &str) {
        TrieNode *cur = _root;
        for (char ch : str) {
            int ind = ch - 'a';
            if (cur->_children[ind] == nullptr) {
                cur->_children[ind] = new TrieNode(ch, false);
            }
            cur = cur->_children[ind];
        }
        cur->_is_word = true;
    }

    bool match(const string &str) {
        TrieNode *cur = _root;
        for (char ch : str) {
            int ch_ind = ch - 'a';
            if (cur->_children[ch_ind] == nullptr) {
                return false;
            }
            cur = cur->_children[ch_ind];
            if (cur->_is_word) return true;
        }
        return false;
    }

    bool match_substr(const string &str) {
        int n = str.size();
        for (int i = 0; i < n; ++i) {
            if (match(str.substr(i))) {
                return true;
            }
        }
        return false;
    }

   private:
    TrieNode *_root = nullptr;
};

int main() {
    int x, y;
    string str;
    cin >> x;
    Trie trie;
    for (int i = 0; i < x; ++i) {
        cin >> str;
        trie.add(str);
    }
    cin >> y;
    for (int i = 0; i < y; ++i) {
        cin >> str;
        cout << (trie.match_substr(str) ? "yes\n" : "no\n");
    }
    return 0;
}
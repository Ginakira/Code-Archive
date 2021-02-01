// LeetCode 212 单词搜索II
#include <vector>
#include <string>
using namespace std;

// 4ms 字典树 + 带节点回溯 + 剪质
class TrieNode {
   public:
    TrieNode() : child(26, nullptr) {}
    friend class Solution;

   private:
    string word = "";
    int leafCount = 0;
    vector<TrieNode *> child;
};

class Solution {
   private:
    int rows, cols;
    vector<string> result;

   public:
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words) {
        rows = board.size(), cols = board[0].size();
        TrieNode *root = new TrieNode();
        for (const auto &word : words) {
            TrieNode *p = root;
            for (const auto &c : word) {
                int ind = c - 'a';
                if (p->child[ind] == nullptr) {
                    ++p->leafCount;
                    p->child[ind] = new TrieNode();
                }
                p = p->child[ind];
            }
            p->word = word;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(board, root, i, j);
            }
        }
        return result;
    }

    void dfs(vector<vector<char>> &board, TrieNode *root, int i, int j) {
        char c = board[i][j];
        if (c == '.' || root->child[c - 'a'] == nullptr) {
            return;
        }
        TrieNode *node = root->child[c - 'a'];
        if (node->word != "") {
            result.emplace_back(node->word);
            node->word = "";
        }
        board[i][j] = '.';
        if (i > 0) dfs(board, node, i - 1, j);
        if (j > 0) dfs(board, node, i, j - 1);
        if (i < rows - 1) dfs(board, node, i + 1, j);
        if (j < cols - 1) dfs(board, node, i, j + 1);
        board[i][j] = c;
        if (node->leafCount == 0) {
            --root->leafCount;
            delete node;
            root->child[c - 'a'] = nullptr;
        }
        return;
    }
};
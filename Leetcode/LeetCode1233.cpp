// LeetCode 1233 删除子文件夹

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 private:
  class TrieNode {
   public:
    TrieNode(const std::string &word) : word_(word), path_ind_(-1) {}
    TrieNode() : TrieNode(string{}) {};

    void insert(const vector<std::string> &tokens, int path_ind) {
      TrieNode *node = this;
      for (auto &token : tokens) {
        if (!node->children_.count(token)) {
          node->children_[token] = new TrieNode(token);
        }
        node = node->children_[token];
      }
      node->path_ind_ = path_ind;
    }

    std::string word_;
    int path_ind_;
    std::unordered_map<std::string, TrieNode *> children_;
  };

 public:
  vector<string> removeSubfolders(vector<string> &folders) {
    TrieNode *root = new TrieNode();
    auto spliter = [&](std::string &path) -> vector<string> {
      vector<string> tokens;
      string str;
      for (char ch : path) {
        if (ch == '/') {
          if (!str.empty()) {
            tokens.emplace_back(str);
            str.clear();
          }
          continue;
        }
        str += ch;
      }
      if (!str.empty()) {
        tokens.emplace_back(str);
      }
      return tokens;
    };
    for (int i = 0; i < folders.size(); ++i) {
      auto paths = spliter(folders[i]);
      root->insert(paths, i);
    }

    vector<string> ans;
    std::function<void(TrieNode *)> dfs = [&](TrieNode *root) {
      if (!root) {
        return;
      }
      if (root->path_ind_ != -1) {
        ans.emplace_back(folders[root->path_ind_]);
        return;
      }
      for (auto &[_, node] : root->children_) {
        dfs(node);
      }
    };
    dfs(root);
    return ans;
  }
};

class Solution3 {
 private:
  struct Trie {
    Trie() : ref(-1) {}

    unordered_map<string, Trie *> children;
    int ref;
  };

 public:
  vector<string> removeSubfolders(vector<string> &folder) {
    auto split = [](const string &s) {
      vector<string> ret;
      string cur;
      stringstream ss(s);
      while (getline(ss, cur, '/')) {
        if (!cur.empty()) {
          ret.emplace_back(cur);
        }
      }
      return ret;
    };
    Trie *root = new Trie();
    for (int i = 0; i < folder.size(); ++i) {
      vector<string> path = split(folder[i]);
      Trie *cur = root;
      for (const std::string &name : path) {
        if (!cur->children.count(name)) {
          cur->children[name] = new Trie();
        }
        cur = cur->children[name];
      }
      cur->ref = i;
    }

    vector<string> ans;

    function<void(Trie *)> dfs = [&](Trie *cur) {
      if (cur->ref != -1) {
        ans.emplace_back(folder[cur->ref]);
        return;
      }
      for (auto &&[_, child] : cur->children) {
        dfs(child);
      }
    };
    dfs(root);
    return ans;
  }
};
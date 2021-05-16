// LeetCode 421 数组中两个数的最大异或值
#include <vector>
using namespace std;

// 字典树 尽量向与当前二进制位相反的方向查找
class Trie {
   private:
    Trie *next[2] = {nullptr};

   public:
    Trie() {}
    void insert(int num) {
        Trie *root = this;
        for (int i = 30; i >= 0; --i) {
            int digit = num >> i & 1;
            if (!root->next[digit]) {
                root->next[digit] = new Trie();
            }
            root = root->next[digit];
        }
    }

    int search(int num) {
        Trie *root = this;
        int result = 0;
        for (int i = 30; i >= 0; --i) {
            int digit = num >> i & 1;
            if (root->next[!digit]) {
                result = result * 2 + !digit;
                root = root->next[!digit];
            } else {
                result = result * 2 + digit;
                root = root->next[digit];
            }
        }
        return result ^ num;
    }
};

class Solution {
   public:
    int findMaximumXOR(vector<int> &nums) {
        Trie *root = new Trie();
        for (int &num : nums) {
            root->insert(num);
        }
        int answer = 0;
        for (int &num : nums) {
            answer = max(answer, root->search(num));
        }
        return answer;
    }
};
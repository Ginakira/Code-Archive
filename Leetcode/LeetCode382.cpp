// LeetCode 382 链表随机节点

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   private:
    ListNode *head_;

   public:
    Solution(ListNode *head) { this->head_ = head; }

    int getRandom() {
        int i = 1, ans = 0;
        for (ListNode *node = head_; node != nullptr; node = node->next) {
            if (rand() % i == 0) {
                ans = node->val;
            }
            ++i;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
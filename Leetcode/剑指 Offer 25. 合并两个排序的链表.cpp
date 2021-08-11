// 剑指 Offer 25. 合并两个排序的链表

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode _dummy_head(-1), *dummy_head = &_dummy_head;
        ListNode *cur_a = l1, *cur_b = l2, *cur = dummy_head;
        while (cur_a || cur_b) {
            if (cur_b == nullptr ||
                (cur_a != nullptr && cur_a->val < cur_b->val)) {
                cur->next = cur_a;
                cur_a = cur_a->next;
            } else {
                cur->next = cur_b;
                cur_b = cur_b->next;
            }
            cur = cur->next;
        }
        return dummy_head->next;
    }
};
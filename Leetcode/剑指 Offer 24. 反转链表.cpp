// 剑指 Offer 24. 反转链表

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
    ListNode* reverseList(ListNode* head) {
        ListNode _dummy_head(-1), *dummy_head = &_dummy_head;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next_node = cur->next;
            cur->next = dummy_head->next;
            dummy_head->next = cur;
            cur = next_node;
        }
        return dummy_head->next;
    }
};
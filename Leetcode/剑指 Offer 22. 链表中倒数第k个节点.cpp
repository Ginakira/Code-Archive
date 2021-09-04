// 剑指 Offer 22. 链表中倒数第k个节点

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
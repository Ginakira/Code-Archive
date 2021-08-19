// LeetCode 25 K个一组翻转链表

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
    tuple<ListNode *, ListNode *> reverse_section(ListNode *head,
                                                  ListNode *tail) {
        ListNode *cur = head;
        while (cur != tail) {
            ListNode *temp = cur->next;
            cur->next = tail->next;
            tail->next = cur;
            cur = temp;
        }
        return {tail, head};
    }

   public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr) return head;
        ListNode _dummy(-1, head), *dummy = &_dummy;
        ListNode *prev = dummy, *cur = head;
        while (cur != nullptr) {
            ListNode *tail = prev;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (tail == nullptr) {
                    return dummy->next;
                }
            }
            ListNode *nex = tail->next;
            ListNode *new_head, *new_tail;
            tie(new_head, new_tail) = reverse_section(cur, tail);

            prev->next = new_head;
            prev = new_tail;
            cur = prev->next;
        }
        return dummy->next;
    }
};
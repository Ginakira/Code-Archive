// LeetCode 148 排序链表

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
   public:
    ListNode *sortList(ListNode *head) { return sort_list(head, nullptr); }

   private:
    ListNode *sort_list(ListNode *head, ListNode *tail) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == tail) {
            head->next = nullptr;  // IMPORTANT
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        return merge_list(sort_list(head, mid), sort_list(mid, tail));
    }

    ListNode *merge_list(ListNode *head_a, ListNode *head_b) {
        if (head_a == nullptr) return head_b;
        if (head_b == nullptr) return head_a;
        ListNode _dummy(-1), *dummy = &_dummy;
        ListNode *pa = head_a, *pb = head_b, *cur = dummy;
        while (pa != nullptr || pb != nullptr) {
            if (pb == nullptr || (pa != nullptr && pa->val <= pb->val)) {
                cur->next = pa;
                pa = pa->next;
            } else {
                cur->next = pb;
                pb = pb->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
// 剑指 Offer II 078. 合并排序链表

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
    ListNode *merge_two_lists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode _dummy(-1), *dummy = &_dummy;
        ListNode *pa = a, *pb = b, *cur = dummy;
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

    ListNode *merge(vector<ListNode *> &lists, int start, int end) {
        if (start == end) return lists[start];
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        return merge_two_lists(merge(lists, start, mid),
                               merge(lists, mid + 1, end));
    }

   public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};
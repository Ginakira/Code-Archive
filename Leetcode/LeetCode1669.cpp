// LeetCode 1669 合并两个链表

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pf = list1;
        // Goto list1[a] front
        for (int i = 0; i < a - 1; ++i) {
            pf = pf->next;
        }
        ListNode* pb = pf->next;
        for (int i = a; i <= b; ++i) {
            // ListNode *tmp = pb->next;
            // delete pb;
            pb = pb->next;
        }
        pf->next = list2;
        ListNode* pl2 = list2;
        while (pl2->next) {
            pl2 = pl2->next;
        }
        pl2->next = pb;
        return list1;
    }
};
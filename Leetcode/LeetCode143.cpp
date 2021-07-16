// LeetCOde 143 重排链表

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

// 线性表 + 双指针 重建链表
class Solution {
   public:
    void reorderList(ListNode *head) {
        vector<ListNode *> vec;
        ListNode *p = head;
        while (p) {
            vec.emplace_back(p);
            p = p->next;
        }
        int left = 0, right = vec.size() - 1;
        while (left < right) {
            vec[left]->next = vec[right];
            ++left;
            if (left == right) {
                break;
            }
            vec[right]->next = vec[left];
            --right;
        }
        vec[left]->next = nullptr;
        return;
    }
};

// 寻找中点 反转后半部分 合并
class Solution2 {
   private:
    ListNode *getMidNode(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    void mergeList(ListNode *la, ListNode *lb) {
        if (!la || !lb) {
            return;
        }
        while (la && lb) {
            ListNode *tmp_a = la->next, *tmp_b = lb->next;
            la->next = lb;
            lb->next = tmp_a;

            la = tmp_a, lb = tmp_b;
        }
        return;
    }

   public:
    void reorderList(ListNode *head) {
        if (!head) return;

        ListNode *mid = getMidNode(head);
        ListNode *list1 = head, *list2 = mid->next;
        mid->next = nullptr;
        list2 = reverseList(list2);
        mergeList(list1, list2);
    }
};
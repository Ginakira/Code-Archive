// 回文链表
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//解法1: 空间复杂度O(N) 或可以复制后使用双指针对比是否回文
class Solution {
   public:
    bool isPalindrome(ListNode *head) {
        vector<int> nor, rev;
        for (auto p = head; p; p = p->next) {
            nor.push_back(p->val);
        }
        rev = nor;
        reverse(nor.begin(), nor.end());
        return nor == rev;
    }
};

//解法2: 将链表的后一半原地翻转 进行比较
int get_length(struct ListNode *head) {
    int n = 0;
    while (head) n++, head = head->next;
    return n;
}

struct ListNode *reverse(struct ListNode *head, int n) {
    struct ListNode ret(-1), *p = head, *q;
    while (n--) p = p->next;
    ret.next = NULL;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

bool isPalindrome2(struct ListNode *head) {
    int len = get_length(head);
    struct ListNode *p = head, *q = reverse(head, (len + 1) >> 1);
    while (q) {
        if (p->val - q->val) return false;
        p = p->next, q = q->next;
    }
    return true;
}

// 解法2-2: 使用快慢指针走到链表中央位置
struct ListNode *reverse(struct ListNode *head) {
    struct ListNode ret(-1), *p = head, *q;
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    p = slow;
    ret.next = NULL;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

bool isPalindrome3(struct ListNode *head) {
    struct ListNode *p = head, *q = reverse(head);
    while (q) {
        if (p->val - q->val) return false;
        p = p->next, q = q->next;
    }
    return true;
}
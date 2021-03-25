// 删除排序链表中的重复元素 II
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 解法1: 先遍历一遍 使用哈希map计数 然后使用通常方法删除重复节点 12ms
class Solution {
   public:
    ListNode *deleteDuplicates(ListNode *head) {
        unordered_map<int, int> mark;
        ListNode *dummy = new ListNode(-1), *p = head;
        while (p) mark[p->val]++, p = p->next;
        dummy->next = head, p = dummy;
        while (p->next) {
            if (mark[p->next->val] > 1) {
                ListNode *delNode = p->next;
                p->next = delNode->next;
                delete delNode;
            } else {
                p = p->next;
            }
        }
        return dummy->next;
    }
};

// 解法2:
// 因为是排序数组，所以新增一个指针mov用于向后走，mov初始位置为p的下下一位
// 每次对比当前的下一个以及mov位置的值是否相同，如果相同，mov继续向后走
// 直到找到第一个不相同的位置，直接更改指向。但是这样的缺点是直接更改了指向，没有进行相应的内存释放
class Solution2 {
   public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(-1), *p = head, *mov = head;
        bool flag = false;
        dummy->next = head, p = dummy;
        while (p->next) {
            flag = false;
            mov = p->next->next;
            while (mov && p->next->val == mov->val)
                mov = mov->next, flag = true;
            if (flag) {
                p->next = mov;
            } else {
                p = p->next;
            }
        }
        return dummy->next;
    }
};

class Solution3 {
   public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode dummy(0, head);
        ListNode *d_node = &dummy, *cur = d_node;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            if (cur->next->val == cur->next->next->val) {
                int target = cur->next->val;
                while (cur->next != nullptr && cur->next->val == target) {
                    ListNode *d_node = cur->next;
                    cur->next = cur->next->next;
                    delete d_node;
                }
            } else {
                cur = cur->next;
            }
        }
        return d_node->next;
    }
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *vnode = new ListNode(0);
        vnode->next = head;
        ListNode *p = head, *pre = vnode;
        while(p) {
            if(p->val == val) {
                ListNode *delete_node = p;
                pre->next = delete_node->next;
                delete delete_node;
            } else {
                pre = p;
            }
            p = pre->next;
        }
        return vnode->next;
    }
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *vnode = new ListNode(0);
        vnode->next = head;
        ListNode *p = head, *pre = vnode;
        while (p) {
            if (p->val == val) {
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

//使用哑结点方法 从哑结点开始，如果当前结点下一个需要删除则删除，否则向后走
class Solution2 {
   public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *yummy = new ListNode(0), *p;
        yummy->next = head, p = yummy;
        while (p->next) {
            if (p->next->val == val) {
                ListNode *delNode = p->next;
                p->next = delNode->next;
                delete delNode;
            } else {
                p = p->next;
            }
        }
        return yummy->next;
    }
};
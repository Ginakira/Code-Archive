struct ListNode {
    int val;
    struct ListNode *next;
};

// 先使用快慢指针走到第一次相遇的点 然后其中一个指针向前走直到再次相遇
// 这样就可以计算出环的长度 然后从头部开始走 其中一个指针向前走环长度步数
// 然后同时走 直到相遇 即为入环的第一个节点
struct ListNode *detectCycle(struct ListNode *head) {
    if (!head || !head->next) return nullptr;
    struct ListNode *p = head, *q = head;
    do {
        p = p->next;
        q = q->next;
        if (!q || !q->next) return nullptr;
        q = q->next;
    } while (p != q);
    int cnt = 0;
    do {
        cnt++;
        q = q->next;
    } while (p != q);
    p = head, q = head;
    while (cnt--) q = q->next;
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}
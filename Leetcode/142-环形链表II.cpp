struct ListNode {
    int val;
    struct ListNode *next;
};

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
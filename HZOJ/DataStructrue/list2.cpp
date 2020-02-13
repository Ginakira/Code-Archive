#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct List {
    ListNode head;
    int length;
} List;

ListNode *getNewNode(int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

List *getLinkList() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode *p = &(l->head), *node = getNewNode(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length++;
    return 1;
}

int erase(List *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->length--;
    return 1;
}

int reverse(List *l) {
    if (l == NULL) return 0;
    ListNode *p = l->head.next, *q;
    l->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return 1;
}

void output(List *l, int val) {
    int cnt = 0, tmp;
    bool flag = false;
    cnt += printf("List(%d) = [", l->length);
    for (ListNode *p = l->head.next; p; p = p->next) {
        tmp = printf("%d->", p->data);
        if (p->data == val)
            flag = true;
        else
            !flag && (cnt += tmp);
    }
    printf("NULL]\n");
    while (cnt--) printf(" ");
    printf("↑\n");
    return;
}

void clear_listNode(ListNode *node) {
    if (node == NULL) return;
    free(node);
    return;
}

void clear_list(List *l) {
    if (l == NULL) return;
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_listNode(p);
        p = q;
    }
    free(l);
    return;
}

int main() {
#define max_op 20
    srand(time(0));
    List *l = getLinkList();
    int op, ind, val;
    for (int i = 0; i < max_op; ++i) {
        op = rand() % 4;
        ind = rand() % (l->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0: {
                printf("Reversed list = %d\n", reverse(l));
            } break;
            case 1:
            case 2: {
                printf("Insert %d at %d to list = %d\n", val, ind,
                       insert(l, ind, val));
            } break;
            case 3: {
                printf("Erase item at %d from list = %d\n", ind, erase(l, ind));
            } break;
        }
        output(l, val);
        printf("\n");
    }
    clear_list(l);
    return 0;
}
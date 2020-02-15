/*
    双向循环链表 已完成
     - 更改初始化列表时两个虚拟结点的指向
     - 输出方式改变
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNode {
    int data;
    struct ListNode *next, *pre;
} ListNode;

typedef struct List {
    ListNode head, tail;
    int length;
} List;

ListNode *getNewNode(int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = p->pre = NULL;
    return p;
}

List *getLinkList() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = &(l->tail);
    l->head.pre = &(l->tail);
    l->tail.pre = &(l->head);
    l->tail.next = &(l->head);
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode *p = &(l->head), *node = getNewNode(val);
    while (ind--) p = p->next;
    node->next = p->next;
    node->pre = p;
    p->next = node;
    node->next->pre = node;
    l->length++;
    return 1;
}

int erase(List *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *node;
    while (ind--) p = p->next;
    node = p->next;
    p->next = node->next;
    node->next->pre = p;
    free(node);
    l->length--;
    return 1;
}

void forward_output(List *l) {
    ListNode *p = l->head.next;
    printf("Forward List(%d) = [", l->length);
    for (int i = 0; i < 2 * l->length; ++i) {
        i &&printf("->");
        if (p == &(l->head)) {
            printf("HEAD");
        } else if (p == &(l->tail)) {
            printf("TAIL");
        } else {
            printf("%d", p->data);
        }
        p = p->next;
    }
    printf("]\n");
    return;
}

void reverse_output(List *l) {
    ListNode *p = l->tail.pre;
    printf("Reverse List(%d) = [", l->length);
    for (int i = 0; i < 2 * l->length; ++i) {
        i &&printf("->");
        if (p == &(l->head)) {
            printf("HEAD");
        } else if (p == &(l->tail)) {
            printf("TAIL");
        } else {
            printf("%d", p->data);
        }
        p = p->pre;
    }
    printf("]\n");
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
    while (p != &(l->tail)) {
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
            case 0:
            case 1:
            case 2: {
                printf("Insert %d at %d to list = %d\n", val, ind,
                       insert(l, ind, val));
            } break;
            case 3: {
                printf("Erase item at %d from list = %d\n", ind, erase(l, ind));
            } break;
        }
        forward_output(l);
        reverse_output(l);
        printf("\n");
    }
    clear_list(l);
    return 0;
}
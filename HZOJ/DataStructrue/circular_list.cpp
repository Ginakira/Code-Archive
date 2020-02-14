/*
    循环链表 已完成
     - 修改链表初始化的head指向（指向自己）
     - reverse操作时，head指向变化（指向自己）
     - 输出改为长度2倍 以体现循环效果
*/
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

ListNode *get_new_node(int val) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = val;
    node->next = NULL;
    return node;
}

List *get_new_list() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = &(l->head);
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val) {
    if (!l) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode *node = get_new_node(val), *p = &(l->head);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length++;
    return 1;
}

int erase(List *l, int ind) {
    if (!l) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *del_node;
    while (ind--) p = p->next;
    del_node = p->next;
    p->next = del_node->next;
    free(del_node);
    l->length--;
    return 1;
}

int reverse(List *l) {
    if (!l) return 0;
    if (!l->length) return 0;
    ListNode *p = l->head.next;
    l->head.next = &(l->head);
    for (int i = 0; i < l->length; ++i) {
        ListNode *q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return 1;
}

void output(List *l) {
    printf("List(%d) = [", l->length);
    // for (ListNode *p = l->head.next; p; p = p->next) {
    ListNode *p = l->head.next;
    for (int i = 0; i <= 2 * l->length; ++i, p = p->next) {
        if (p == &(l->head))
            printf("HEAD->");
        else
            printf("%d->", p->data);
    }
    printf("...]\n");
    return;
}

void clear_node(ListNode *node) {
    if (!node) return;
    free(node);
    return;
}

void clear_list(List *l) {
    if (!l) return;
    ListNode *p = l->head.next, *q;
    while (l->length--) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    return;
}

int main() {
#define max_op 20
    srand(time(0));
    List *l = get_new_list();
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
        output(l);
        printf("\n");
    }
    clear_list(l);
    return 0;
}
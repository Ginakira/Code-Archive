#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            printf("failed\n");
            return head;
        }
        head = node;
        printf("success\n");
        return head;
    }
    if (index == 0) {
        node->next = head;
        head = node;
        printf("success\n");
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
        printf("success\n");
        return head;
    }
    printf("failed\n");
    return head;
}

void output(LinkedList head) {
    if (head == NULL) {
        return;
    }
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

LinkedList delete_node(LinkedList head, int index) {
    if (head == NULL) {
        printf("failed\n");
        return head;
    }
    int count = 0;
    Node *c_node = head;
    if (index == 0) {
        head = head->next;
        free(c_node);
        printf("success\n");
        return head;
    }
    while (c_node->next != NULL && count < index - 1) {
        c_node = c_node->next;
        count++;
    }
    if (c_node->next != NULL && count == index - 1) {
        Node *d_node = c_node->next;
        c_node->next = d_node->next;
        free(d_node);
    }
    printf("success\n");
    return head;
}

LinkedList reverse(LinkedList head) {
    if (head == NULL) {
        return head;
    }
    Node *c_node, *n_node;
    c_node = head->next;
    head->next = NULL;
    while (c_node != NULL) {
        n_node = c_node->next;
        c_node->next = head;
        head = c_node;
        c_node = n_node;
    }
    return head;
}

void clear(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main() {
    LinkedList linkedlist = NULL;
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int leixing;
        scanf("%d", &leixing);
        if (leixing == 1) {
            int index, val;
            scanf("%d%d", &index, &val);
            Node *node = (Node *)malloc(sizeof(Node));
            node->data = val;
            node->next = NULL;
            linkedlist = insert(linkedlist, node, index);
        }
        if (leixing == 2) {
            output(linkedlist);
        }
        if (leixing == 3) {
            int v;
            scanf("%d", &v);
            delete_node(linkedlist, v);
        }
        if (leixing == 4) {
            reverse(linkedlist);
        }
    }
    clear(linkedlist);
    return 0;
}
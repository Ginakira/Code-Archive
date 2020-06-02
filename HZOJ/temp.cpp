#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int op_priority(char op) {
    enum operators { ADD = 1, SUB = 1, MUL = 2, DIV = 2 };
    switch (op) {
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
        default:
            return 0;  // not an operator
    }
}

void number_into_RPN(char infix[], char RPN[], int *iter_infix, int *iter_RPN) {
    while (infix[*iter_infix] != '\0' && !op_priority(infix[*iter_infix]) &&
           infix[*iter_infix] != ')' &&
           infix[*iter_infix] !=
               ' ') {  // put all chars scanned in infix[] into RPN[] until
                       // getting a operator or a spaces or ')'
        RPN[(*iter_RPN)++] = infix[(*iter_infix)++];
    }
    RPN[(*iter_RPN)++] = ' ';
    (*iter_infix)--;  // match the fact that iter_fix is added after a loop
}

int getnum(char RPN[], int *iter_RPN) {
    int rst = 0;
    while (RPN[*iter_RPN] != ' ') {
        rst = rst * 10 + RPN[*iter_RPN] - '0';
        (*iter_RPN)++;
    }
    return rst;
}

void infix_into_RPN(
    char infix[],
    char RPN[]) {  // transfer an infix expression into a reverse Polish
                   // expression (see: Dijkstra's Shunting Yard Algorithm)
    int len = strlen(infix);
    char op_stack[220];
    int iter_infix = 0, iter_RPN = 0, iter_opstack = 0;
    for (; iter_infix < len; iter_infix++) {
        if (infix[iter_infix] == ' ') {
            continue;
        } else if (infix[iter_infix] >= '0' &&
                   infix[iter_infix] <= '9') {  // if scanner gets a number,
                                                // directly put it into RPN[]
            number_into_RPN(infix, RPN, &iter_infix, &iter_RPN);
        } else if (infix[iter_infix] == '(') {  // if scanner gets '(', directly
                                                // put it into op_stack[]
            op_stack[iter_opstack++] = infix[iter_infix];
        } else if (op_priority(
                       infix[iter_infix])) {  // if scanner gets an operator,
                                              // pop all the operators with
                                              // higher or equal priority
            iter_opstack--;
            while (iter_opstack >= 0 && op_priority(op_stack[iter_opstack]) >=
                                            op_priority(infix[iter_infix])) {
                RPN[iter_RPN++] = op_stack[iter_opstack--];
                RPN[iter_RPN++] = ' ';
            }
            iter_opstack++;
            op_stack[iter_opstack++] = infix[iter_infix];
        } else if (infix[iter_infix] ==
                   ')') {  // if scanner gets ')', pop all the pop all the
                           // operators until the first '(' is met
            iter_opstack--;
            while (op_stack[iter_opstack] != '(') {
                RPN[iter_RPN++] = op_stack[iter_opstack--];
                RPN[iter_RPN++] = ' ';
            }
        }
    }
    iter_opstack--;
    while (op_stack[iter_opstack] != '(' && op_stack[iter_opstack] >= 0) {
        RPN[iter_RPN++] = op_stack[iter_opstack--];
        RPN[iter_RPN++] = ' ';
    }
    RPN[iter_RPN] = '\0';
    if (iter_opstack != -1) printf("ERROR: leftover bracket(s)");
}

struct symbnode {
    int num;
    char op;
    struct symbnode *lchild, *rchild;
};

void RPN_into_exprtree(char RPN[], struct symbnode **exprtree) {
    struct symbnode *node_stack[220];
    struct symbnode *newnode;
    int iter_RPN = 0, iter_nstack = 0;

    while (RPN[iter_RPN] != '\0') {
        if (RPN[iter_RPN] >= '0' && RPN[iter_RPN] <= '9') {
            newnode = (struct symbnode *)malloc(sizeof(struct symbnode));
            newnode->num = getnum(RPN, &iter_RPN);
            newnode->op = '\0';  // showing this is not an operator
            newnode->lchild = NULL;
            newnode->rchild = NULL;
            node_stack[iter_nstack++] = newnode;
        } else if (op_priority(RPN[iter_RPN])) {
            newnode = (struct symbnode *)malloc(sizeof(struct symbnode));
            newnode->op = RPN[iter_RPN];

            if ((--iter_nstack) >= 0)
                newnode->rchild = node_stack[iter_nstack];
            else
                newnode->rchild = NULL;

            if ((--iter_nstack) >= 0)
                newnode->lchild = node_stack[iter_nstack];
            else
                newnode->lchild = NULL;

            node_stack[iter_nstack++] = newnode;
        }
        iter_RPN++;
    }

    *exprtree = node_stack[0];
    // if (iter_nstack > 1) printf("ERROR: leftover number(s)");
}

int RPN_into_num(char RPN[]) {
    int num_stack[220];
    int iter_RPN = 0, iter_nstack = 0;
    int len = strlen(RPN);
    for (; iter_RPN < len; iter_RPN++) {
        if (RPN[iter_RPN] == ' ') {
            continue;
        } else if (RPN[iter_RPN] >= '0' && RPN[iter_RPN] <= '9') {
            num_stack[iter_nstack++] = getnum(RPN, &iter_RPN);
        } else {
            iter_nstack--;
            if (RPN[iter_RPN] == '+') {
                num_stack[iter_nstack - 1] += num_stack[iter_nstack];
            } else if (RPN[iter_RPN] == '-') {
                num_stack[iter_nstack - 1] -= num_stack[iter_nstack];
            } else if (RPN[iter_RPN] == '*') {
                num_stack[iter_nstack - 1] *= num_stack[iter_nstack];
            } else if (RPN[iter_RPN] == '/') {
                if (num_stack[iter_nstack] == 0) {
                    // printf("ERROR: divided by 0");
                    num_stack[iter_nstack - 1] = 0;
                    continue;
                }
                num_stack[iter_nstack - 1] /= num_stack[iter_nstack];
            }
            iter_RPN++;
        }
    }
    if (iter_nstack == 1)
        return num_stack[0];
    else {
        // printf("ERROR: leftover operator(s)");
        return num_stack[iter_nstack - 1];
    }
}

int main() {
    char infix[220], RPN[220];
    char tmp;
    struct symbnode *exprtree = NULL;
    int i = 0;

    while ((tmp = getchar()) != '=') infix[i++] = tmp;
    infix[i] = '\0';

    infix_into_RPN(infix, RPN);
    RPN_into_exprtree(RPN, &exprtree);

    printf("%s\n", RPN);

    tmp = exprtree->op;
    printf("%c", tmp);

    if (exprtree->lchild != NULL) {
        tmp = exprtree->lchild->op;
        if (tmp == '\0')
            printf(" %d", exprtree->lchild->num);
        else
            printf(" %c", tmp);
    }

    if (exprtree->rchild != NULL) {
        tmp = exprtree->rchild->op;
        if (tmp == '\0')
            printf(" %d\n", exprtree->rchild->num);
        else
            printf(" %c\n", tmp);
    } else
        printf("\n");

    printf("%d\n", RPN_into_num(RPN));
    return 0;
}
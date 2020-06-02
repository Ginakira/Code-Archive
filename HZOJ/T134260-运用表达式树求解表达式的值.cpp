#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
#define MAX_LEN 256

struct Node {  // 表达式树上节点
    int num;
    char op;
    struct Node *lchild, *rchild;
};

int operator_priority(char);            // 运算符优先级
void infix_to_RPN(char[], char[]);      // 前缀表达式转后缀表达式
void RPN_to_exprtree(char[], Node **);  // 使用后缀表达式生成表达式树
void num_into_RPN(char[], char[], int *, int *);  // 将数字放进RPN数组中
int get_num(char[], int *);  // 将连着的数字转成整型
int cal_num(char[]);         // 计算表达式结果

int main() {
    char infix[MAX_LEN];  // 中缀表达式
    char RPN[MAX_LEN];    // 后缀表达式
    char tmp;
    struct Node *root = NULL;  // 表达式树根节点
    int ind = 0;

    // 读入前缀表达式 直到遇到等号
    while ((tmp = getchar()) != '=') infix[ind++] = tmp;
    infix[ind] = '\0';

    infix_to_RPN(infix, RPN);
    RPN_to_exprtree(RPN, &root);

    tmp = root->op;
    cout << tmp;

    if (root->lchild != NULL) {
        tmp = root->lchild->op;
        if (tmp == '\0')
            cout << ' ' << root->lchild->num;
        else
            cout << ' ' << tmp;
    }

    if (root->rchild != NULL) {
        tmp = root->rchild->op;
        if (tmp == '\0')
            cout << ' ' << root->rchild->num << endl;
        else
            cout << ' ' << tmp << endl;
    } else {
        cout << endl;
    }

    cout << cal_num(RPN) << endl;
    return 0;
}

int operator_priority(char op) {
    enum operators {
        ADD = 1,
        SUB = 1,
        MUL = 2,
        DIV = 2
    };  // 加减优先级为1 乘除为2
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
            return 0;  // 运算符非法
    }
}

void num_into_RPN(char infix[], char RPN[], int *infix_ind, int *RPN_ind) {
    char ch;
    while ((ch = infix[*infix_ind]) && ch != '\0' && !operator_priority(ch) &&
           ch != ')' &&
           ch != ' ') {  // 将所有连着的数字放入RPN 直到遇到空格或运算符
        RPN[(*RPN_ind)++] = infix[(*infix_ind)++];
    }
    RPN[(*RPN_ind)++] = ' ';  // 末尾加入空格
    (*infix_ind)--;
    return;
}

void infix_to_RPN(char infix[], char RPN[]) {
    int len = strlen(infix);
    stack<char> op_stack;
    int infix_ind = 0, RPN_ind = 0;

    for (infix_ind = 0; infix_ind < len; ++infix_ind) {  // 扫描前缀表达式
        if (isblank(infix[infix_ind])) {
            continue;
        } else if (isdigit(infix[infix_ind])) {  // 如果是数字则放进RPN中
            num_into_RPN(infix, RPN, &infix_ind, &RPN_ind);
        } else if (infix[infix_ind] == '(') {  // 是左括号 放入栈顶
            op_stack.push(infix[infix_ind]);
        } else if (
            operator_priority(
                infix
                    [infix_ind])) {  // 如果是运算符
                                     // 弹出栈中所有比它优先级高或相等的运算符放入RPN
            while (!op_stack.empty() &&
                   operator_priority(op_stack.top()) >=
                       operator_priority(infix[infix_ind])) {
                RPN[RPN_ind++] = op_stack.top();
                op_stack.pop();
                RPN[RPN_ind++] = ' ';
            }
            op_stack.push(infix[infix_ind]);
        } else if (infix[infix_ind] ==
                   ')') {  // 如果是右括号 弹出遇到左括号之前的所有运算符
            while (!op_stack.empty() && op_stack.top() != '(') {
                RPN[RPN_ind++] = op_stack.top();
                op_stack.pop();
                RPN[RPN_ind++] = ' ';
            }
            if (!op_stack.empty() && op_stack.top() == '(') op_stack.pop();
        }
    }
    while (!op_stack.empty() && op_stack.top() != '(') {
        RPN[RPN_ind++] = op_stack.top();
        op_stack.pop();
        RPN[RPN_ind++] = ' ';
    }
    RPN[RPN_ind] = '\0';
    return;
}

int get_num(char RPN[], int *ind) {
    int ret = 0;
    while (RPN[*ind] != ' ') {
        ret = ret * 10 + RPN[*ind] - '0';
        (*ind)++;
    }
    return ret;
}

void RPN_to_exprtree(char RPN[], Node **root) {
    stack<Node *> node_stack;
    Node *node;
    int RPN_ind = 0;

    while (RPN[RPN_ind] != '\0') {
        if (isdigit(RPN[RPN_ind])) {
            node = new Node;
            node->num = get_num(RPN, &RPN_ind);
            node->op = 0;  // 表示此节点是数字节点
            node->lchild = node->rchild = NULL;
            node_stack.push(node);
        } else if (operator_priority(RPN[RPN_ind])) {
            //  如果是运算符 取出栈顶两个节点作为新节点左右子树 并入栈
            node = new Node;
            node->op = RPN[RPN_ind];
            node->num = 0;

            if (!node_stack.empty()) {
                node->rchild = node_stack.top();
                node_stack.pop();
            } else {
                node->rchild = NULL;
            }

            if (!node_stack.empty()) {
                node->lchild = node_stack.top();
                node_stack.pop();
            } else {
                node->lchild = NULL;
            }

            node_stack.push(node);
        }
        RPN_ind++;
    }
    *root = node_stack.top();
    return;
}

int cal_num(char RPN[]) {
    stack<int> num_stack;
    int ind = 0, len = strlen(RPN);
    for (ind = 0; ind < len; ++ind) {
        char ch = RPN[ind];
        if (ch == ' ') {
            continue;
        } else if (isdigit(ch)) {
            num_stack.push(get_num(RPN, &ind));
        } else {  // 如果是运算符 则从栈顶取出两个数字进行计算
            int num1, num2, ans = 0;
            num1 = num_stack.top();
            num_stack.pop();
            num2 = num_stack.top();
            num_stack.pop();
            if (ch == '+') {
                ans = num1 + num2;
            } else if (ch == '-') {
                ans = num2 - num1;
            } else if (ch == '*') {
                ans = num2 * num1;
            } else if (ch == '/') {
                if (num1 == 0) {
                    num_stack.push(0);
                    continue;
                }
                ans = num2 / num1;
            }
            num_stack.push(ans);
        }
    }
    return (num_stack.empty() ? 0 : num_stack.top());
}

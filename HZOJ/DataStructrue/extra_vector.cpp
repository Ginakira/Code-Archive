/************************************************************
    File Name : 3.任意类型数组.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2020-02-12 星期三 16:19:19
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

using namespace std;

enum class Type {
    intType,
    doubleType,
    charType,
    stringType,
    floatType,
    nothingType
};

class Node {
   public:
    int int_val = 0;
    char char_val = 0;
    float float_val = 0;
    double double_val = 0;
    const char *string_val = "";
    Type type = Type::nothingType;
    Node() {}
    Node(int value) {
        type = Type::intType;
        int_val = value;
    }
    Node(char value) {
        type = Type::charType;
        char_val = value;
    }
    Node(float value) {
        type = Type::floatType;
        float_val = value;
    }
    Node(double value) {
        type = Type::doubleType;
        double_val = value;
    }
    Node(const char *value) {
        type = Type::stringType;
        string_val = value;
    }
    Node(const Node &node) {
        switch (node.type) {
            case Type::intType:
                this->int_val = node.int_val;
                break;
            case Type::charType:
                this->char_val = node.char_val;
                break;
            case Type::floatType:
                this->float_val = node.float_val;
                break;
            case Type::doubleType:
                this->double_val = node.double_val;
                break;
            case Type::stringType:
                this->string_val = node.string_val;
                break;
            default:
                break;
        }
        this->type = node.type;
    }
    void operator=(int value) {
        type = Type::intType;
        int_val = value;
    }
    void operator=(char value) {
        type = Type::charType;
        char_val = value;
    }
    void operator=(float value) {
        type = Type::floatType;
        float_val = value;
    }
    void operator=(double value) {
        type = Type::doubleType;
        double_val = value;
    }
    void operator=(const char *value) {
        type = Type::stringType;
        string_val = value;
    }
    void operator=(Node &node) {
        switch (node.type) {
            case Type::intType:
                this->int_val = node.int_val;
                break;
            case Type::charType:
                this->char_val = node.char_val;
                break;
            case Type::floatType:
                this->float_val = node.float_val;
                break;
            case Type::doubleType:
                this->double_val = node.double_val;
                break;
            case Type::stringType:
                this->string_val = node.string_val;
                break;
            default:
                break;
        }
        this->type = node.type;
    }
    friend std::ostream &operator<<(std::ostream &output, Node anyType) {
        switch (anyType.type) {
            case Type::intType:
                return output << anyType.int_val;
            case Type::charType:
                return output << anyType.char_val;
            case Type::floatType:
                return output << anyType.float_val;
            case Type::doubleType:
                return output << anyType.double_val;
            case Type::stringType:
                return output << anyType.string_val;
            default:
                break;
        }
        return output;
    }
};

typedef struct Vector {
    Node *data;
    int size, length;
} Vector;

Vector *init(int size) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (Node *)malloc(sizeof(Node) * size);
    v->size = size;
    v->length = 0;
    return v;
}

int expand(Vector *v) {
    int size = v->size;
    Node *p;
    while (size) {
        p = (Node *)realloc(v->data, sizeof(Node) * (v->size + size));
        if (p) break;
        size /= 2;
    }
    if (!p) return 0;
    v->data = p;
    v->size += size;
    return 1;
}

int insert(Vector *vec, int ind, Node node) {
    if (vec == NULL) return 0;
    if (ind < 0 || ind > vec->length) {
        return 0;
    }
    if (vec->length == vec->size) {
        if (!expand(vec)) return 0;
    }
    for (int i = vec->length; i > ind; i--) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = node;
    vec->length++;
    return 1;
}

int erase(Vector *vec, int ind) {
    if (vec == NULL) return 0;
    if (ind < 0 || ind >= vec->length) return 0;
    for (int i = ind; i < vec->length; i++) {
        vec->data[i] = vec->data[i + 1];
    }
    vec->length--;
    return 1;
}

void output(Vector *vec) {
    printf("Vector = [ ");
    for (int i = 0; i < vec->length; i++) {
        cout << vec->data[i] << " ";
    }
    printf(" ]\n");
}

void clear(Vector *vec) {
    if (vec == NULL) return;
    free(vec->data);
    free(vec);
    return;
}

int main() {
    Vector *v = init(10);
#define MAX_OP 50
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 5, ind;
        switch (op) {
            case 4:
            case 2: {
                ind = rand() % (v->length + 3) - 1;
                char value = (rand() % 26) + 'a';
                printf("{%d} INSERT(%d, double(%c)) to vector\n",
                       insert(v, ind, Node(value)), ind, value);
                output(v);
            } break;
            case 3: {
                ind = rand() % (v->length + 3) - 1;
                double value = (rand() % 10000 * 1.0 / 100);
                printf("{%d} INSERT(%d, double(%lf)) to vector\n",
                       insert(v, ind, Node(value)), ind, value);
                output(v);
            } break;
            case 0: {
                ind = rand() % (v->length + 3) - 1;
                int value = rand() % 100;
                printf("{%d} INSERT(%d, int(%d)) to vector\n",
                       insert(v, ind, Node(value)), ind, value);
                output(v);
            } break;
            case 1: {
                ind = rand() % (v->length + 3) - 1;
                printf("ERASE(%d) = %d from Vector\n", ind, erase(v, ind));
                output(v);
            } break;
        }
    }
    clear(v);
    return 0;
}
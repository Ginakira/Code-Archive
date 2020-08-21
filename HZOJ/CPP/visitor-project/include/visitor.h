#pragma once
#include <stack>
#include <string>

#include "Expression.h"
#include "utility.h"
using std::stack;
using std::string;
using std::to_string;

class ExpressionPointer : public Expression::IVisior {
   public:
    string result;
    int level;  // 左右子树表达式的优先级 高到低：数字 乘除 加减

    void Visit(NumberExpression* node);

    void Visit(BinaryExpression* node);
};

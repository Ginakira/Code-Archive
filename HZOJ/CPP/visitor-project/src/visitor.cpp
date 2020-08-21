#include "../include/visitor.h"

#include <sstream>

// TODO
void ExpressionPointer::Visit(NumberExpression* node) {
    std::ostringstream os;
    os << node->Value;
    this->result = os.str();
    this->level = 4;
    return;
}

void ExpressionPointer::Visit(BinaryExpression* node) {
    switch (node->Op) {
        case BinaryOperator::Plus:
        case BinaryOperator::Minus:
            this->level = 1;
            break;
        case BinaryOperator::Multiply:
        case BinaryOperator::Divide:
            this->level = 2;
            break;
    }

    ExpressionPointer lexp_vis, rexp_vis;
    node->First->Accept(&lexp_vis);
    node->Second->Accept(&rexp_vis);
    // 左子树：子节点运算符优先级小于父节点 子节点加括号
    if (lexp_vis.level < this->level) {
        lexp_vis.result = string("(") + lexp_vis.result + string(")");
    }
    // 右子树优先级小于当前节点，加括号
    if (rexp_vis.level < this->level) {
        rexp_vis.result = string("(") + rexp_vis.result + string(")");
    }
    // 右子树优先级与当前相等，
    if (rexp_vis.level == this->level &&
        (node->Second->op == BinaryOperator::Minus ||
         node->Second->op == BinaryOperator::Divide)) {
        rexp_vis.result = string("(") + rexp_vis.result + string(")");
    }

    switch (node->Op) {
        case BinaryOperator::Plus:
            this->result = lexp_vis.result + "+" + rexp_vis.result;
            break;
        case BinaryOperator::Minus:
            this->result = lexp_vis.result + "-" + rexp_vis.result;
            break;
        case BinaryOperator::Multiply:
            this->result = lexp_vis.result + "*" + rexp_vis.result;
            break;
        case BinaryOperator::Divide:
            this->result = lexp_vis.result + "/" + rexp_vis.result;
            break;
    }
    return;
}

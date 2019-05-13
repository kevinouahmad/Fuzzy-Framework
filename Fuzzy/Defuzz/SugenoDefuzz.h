//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_SUGENODEFUZZ_H
#define FUZZY_SUGENODEFUZZ_H

#include "../../Core/Expressions/Nary/NaryExpression.h"
#include "../../Core/Expressions/Binary/BinaryExpressionModel.h"
#include "../../Core/Expressions/Binary/BinaryShadowExpression.h"

using namespace core;

namespace fuzzy
{
    template <typename T>
    class SugenoDefuzz : public NaryExpression<T> {
    public:
        T evaluate(std::vector<Expression<T>*>*) const;
    };

    template <typename T>
    T SugenoDefuzz<T>::evaluate(std::vector<Expression<T>*> *operands) const {
        T num = 0, den = 0;
        for (auto operand = operands->begin(); operand != operands->end(); operand++) {
            BinaryExpressionModel<T> *expressionModel = static_cast<BinaryExpressionModel<T>*>(*operand);
            const BinaryShadowExpression<T> *op = static_cast<BinaryShadowExpression<T>*>(expressionModel->getOperator());
            const SugenoThen<T> *then = static_cast<SugenoThen<T>*>(op->getTarget());
            T premiseValue = then->getPremiseValue();

            num += premiseValue * (*operand)->evaluate();
            den += premiseValue;
        }
        if (den != 0) {
            return num / den;
        }
        return NULL;
    }
}

#endif //FUZZY_SUGENODEFUZZ_H

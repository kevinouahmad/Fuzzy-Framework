//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_NARYEXPRESSIONMODEL_H
#define FUZZY_NARYEXPRESSIONMODEL_H

#include "NaryExpression.h"

namespace core {
    template <typename T>
    class NaryExpressionModel : public NaryExpression<T>, public Expression<T> {
    public:
        NaryExpressionModel(NaryExpression<T>*, std::vector<Expression<T>*>*);
        virtual T evaluate() const;
        virtual T evaluate(std::vector<Expression<T>*>) const;

    private:
        NaryExpression<T> *op;
        std::vector<Expression<T>*> operands;
    };

    template <typename T>
    NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T> *_op, std::vector<Expression<T>*> *operands) : op(_op),
                                                                                                                operands(_operands) {}

    template <typename T>
    T NaryExpressionModel<T>::evaluate() const {
        if (!operands->empty()) {
            return op->evaluate(operands);
        }
        return NULL;
    }

    template <typename T>
    T NaryExpressionModel<T>::evaluate(std::vector<core::Expression<T>*> operands) const {
        if (!operands->empty() && op != nullptr) {
            return op->evaluate(operands);
        }
        return NULL;
    }
}
#endif //FUZZY_NARYEXPRESSIONMODEL_H

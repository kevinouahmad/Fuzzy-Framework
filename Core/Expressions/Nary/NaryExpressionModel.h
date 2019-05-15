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
        NaryExpressionModel(NaryExpression<T> *ope, std::vector<Expression<T>*> *operands);
        virtual ~NaryExpressionModel() = default;

        virtual T evaluate() const;
        virtual T evaluate(std::vector<Expression<T>*> *operands) const;

    private:
        NaryExpression<T> *ope; // n-ary operator
        std::vector<Expression<T>*> *operands;
    };

    template<typename T>
    NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* ope,
                                                std::vector<Expression<T>*> *operands) :
            ope(ope), operands(operands) {
    }

    template<typename T>
    T NaryExpressionModel<T>::evaluate() const {
        if (operands->empty()) {
            return NULL;
        }
        return evaluate(operands);
    }

    template<typename T>
    T NaryExpressionModel<T>::evaluate(std::vector<Expression<T>*> *operands) const {
        if (operands->empty()) {
            return NULL;
        }
        if (ope == NULL) {
            return NULL;
        }
        return ope->evaluate(operands);
    }

}
#endif //FUZZY_NARYEXPRESSIONMODEL_H

//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_EXPRESSIONFACTORY_H
#define FUZZY_EXPRESSIONFACTORY_H

#include <set>

#include "Expression.h"
#include "Binary/BinaryExpression.h"
#include "Unary/UnaryExpression.h"
#include "Nary/NaryExpression.h"
#include "../ValueModel.h"

namespace core {
    template <typename T>
    class ExpressionFactory {
    public:
        virtual ~ExpressionFactory();
        virtual Expression<T>* hold(Expression<T>*);
        virtual ValueModel<T>* newValue(T);

    protected:
        virtual Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
        virtual Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
        virtual Expression<T>* newNary(NaryExpression<T>*, std::vector<Expression<T>*>*);

    private:
        std::set<Expression<T>*> mem;
    };

    template <typename T>
    ExpressionFactory<T>::~ExpressionFactory() {
        for (auto *expression : mem) {
            delete(expression);
        }
    }

    template <typename T>
    Expression<T>* ExpressionFactory<T>::hold(Expression<T> *expression) {
        mem.insert(expression);
        return expression;
    }

    template <typename T>
    ValueModel<T>* ExpressionFactory<T>::newValue(T value) {
        return static_cast<ValueModel<T>*>(hold(new ValueModel<T>(value)));
    }

    template <typename T>
    Expression<T>* ExpressionFactory<T>::newUnary(core::UnaryExpression<T> *op, core::Expression<T> *expression) {
        return hold(new UnaryExpressionModel(op, expression));
    }

    template <typename T>
    Expression<T>* ExpressionFactory<T>::newBinary(core::BinaryExpression<T> *op, core::Expression<T> *left,
                                                   core::Expression<T> *right) {
        return hold(new BinaryExpressionModel(op, left, right));
    }

    template <typename T>
    Expression<T>* ExpressionFactory<T>::newNary(core::NaryExpression<T> *op, std::vector<core::Expression<T> *> *operands) {
        return hold(new NaryExpressionModel(op, operands));
    }

}
#endif //FUZZY_EXPRESSIONFACTORY_H

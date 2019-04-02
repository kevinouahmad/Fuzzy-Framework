//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
#include "../Expression.h"

namespace core
{
    template <class T>
    class UnaryExpressionModel :public Expression<T>, public UnaryExpression<T>
    {
    public:
        UnaryExpressionModel(UnaryExpression<T>* = NULL, Expression<T>* = NULL);

        T evaluate() const;
        T evaluate(Expression<T>*) const;

        UnaryExpression<T>* getOperator();
        Expression<T> getOperand();
        void setOperator(UnaryExpression<T>*);
        void setOperand(Expression<T>*);

    private:
        UnaryExpression<T>* ope;
        Expression<T>* operand;
    };

    template <class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>*_ope, Expression<T>*_operand):
            ope(_ope),operand(_operand)
    {}

    template <class T>
    T UnaryExpressionModel<T>::evaluate() const
    {
        if (operand != NULL)
            return evaluate(operand);
        return NULL;
    }

    template <class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const
    {
        if (ope != NULL)
            return ope->evaluate(o);
        return NULL;
    }

    template <class T>
    UnaryExpression<T>* UnaryExpressionModel<T>::getOperator()
    {
        return ope;
    }

    template <class T>
    UnaryExpression<T>* UnaryExpressionModel<T>::getOperand()
    {
        return operand;
    }

    template <class T>
    void UnaryExpressionModel<T>::setOperator(UnaryExpression<T>*_ope)
    {
        ope = *_ope;
    }

    template <class T>
    void UnaryExpressionModel<T>::setOperand(Expression<T>*_operand)
    {
        operand = *_operand;
    }

}

#endif //FUZZY_UNARYEXPRESSIONMODEL_H

//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"
#include "../Expression.h"

namespace core
{
    template <class T>
    class BinaryExpressionModel :public Expression<T>, public BinaryExpression<T> {
    public:
        BinaryExpressionModel(BinaryExpression<T>* op, Expression<T>* left, Expression<T>* right);

        Expression<T>* getLeft() const;
        Expression<T>* getRight() const;
        BinaryExpression<T>* getOperator();
        void setLeft(Expression<T>*);
        void setRight(Expression<T>*);
        void setOperator(BinaryExpression<T>*);

        T evaluate() const;
        T evaluate(Expression<T>*, Expression<T>*) const;

    private:
        Expression<T>* left;
        Expression<T>* right;
        BinaryExpression<T>* op;
    };

    template <class T>

    BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>*_op, Expression<T>*_left, Expression<T>*_right) :
            op(_op), left(_left), right(_right) {}

    template <class T>
    Expression<T>* BinaryExpressionModel<T>::getLeft() const
    {
        return left;
    }

    template <class T>
    Expression<T>* BinaryExpressionModel<T>::getRight() const
    {
        return right;
    }

    template <class T>
    BinaryExpression<T>* BinaryExpressionModel<T>::getOperator()
    {
        return op;
    }

    template <class T>
    void BinaryExpressionModel<T>::setLeft(Expression<T>*_left)
    {
        left = *_left;
    }

    template <class T>
    void BinaryExpressionModel<T>::setRight(Expression<T>*_right)
    {
        right = *_right;
    }

    template <class T>
    void BinaryExpressionModel<T>::setOperator(BinaryExpression<T>*_op)
    {
        op = *_op;
    }

    template <class T>
    T BinaryExpressionModel<T>::evaluate() const
    {
        if (left!= NULL && right!= NULL)
            return evaluate(left, right);
        return NULL;
    }

    template <class T>
    T BinaryExpressionModel<T>::evaluate(Expression<T>* left, Expression<T>* right) const
    {
        if (op != NULL)
            return op->evaluate(left, right);
        return NULL;
    }
}

#endif //FUZZY_BINARYEXPRESSIONMODEL_H

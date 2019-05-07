//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_EXPRESSIONFACTORY_H
#define FUZZY_EXPRESSIONFACTORY_H

#include"Expression.h"

namespace core{
    template <class T>
    class ExpressionFactory{
    public:
        Expression<T>* Hold(Expression<T>*);
        UnaryExpressionModel<T>* newUnary(UnaryExpression<T>* = NULL, Expression<T>* = NULL);
        BinaryExpressionModel<T> * newBinary(BinaryExpression<T>* = NULL, Expression<T>* = NULL, Expression<T>* NULL);
        Expression<T>* new ValueModel(const T&);

    private:
        Expresson<T> *expr;
    };
    template <class T>
    Expression<T>* ExpressionFactory<T>::Hold(Expression<T> *ex){
        *expr=*ex;
        return expr;
    }

    template <class T>
    UnaryExpressionModel<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o){
        return new UnaryExpressionModel<T>(ope,o);
    }

    template <class T>
    BinaryExpressionModel<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r){
        return new BinaryExpressionModel<T>(ope,l,r);
    }

    template <class T>
    Expression<T>* ExpressionFactory<T>::new ValueModel(const T& val){
        return new ValueModel<T>(val);
    }
}
#endif //FUZZY_EXPRESSIONFACTORY_H
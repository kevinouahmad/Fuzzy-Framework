//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_ANDMULT_H
#define FUZZY_ANDMULT_H


#include "../../Core/Operators/And.h"
#include "../../Core/Expressions/Expression.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class AndMult : public And<T>
    {
    public:
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    T AndMult<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        return left->evaluate() * right->evaluate();
    }
}

#endif //FUZZY_ANDMULT_H

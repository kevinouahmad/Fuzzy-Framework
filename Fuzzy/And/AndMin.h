//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_ANDMIN_H
#define FUZZY_ANDMIN_H


#include "../../Core/Operators/And.h"
#include "../../Core/Expressions/Expression.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class AndMin : public And<T>
    {
    public:
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    T AndMin<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        T lv = left->evaluate();
        T rv = right->evaluate();
        return (lv < rv) ? lv : rv;
    }
}

#endif //FUZZY_ANDMIN_H

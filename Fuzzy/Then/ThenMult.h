//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_THENMULT_H
#define FUZZY_THENMULT_H


#include "../../Core/Operators/Or.h"
#include "../../Core/Expressions/Expression.h"
#include "../../Core/Operators/Then.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class ThenMult : public Then<T>
    {
    public:
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    T ThenMult<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        return left->evaluate() * right->evaluate();
    }
}

#endif //FUZZY_THENMULT_H

//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_ORMAX_H
#define FUZZY_ORMAX_H

#include "../../Core/Operators/Or.h"
#include "../../Core/Expressions/Expression.h"


using namespace core;

namespace fuzzy
{
    template <class T>
    class OrMax : public Or<T>
    {
    public:
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    T OrMax<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        T lv = left->evaluate();
        T rv = right->evaluate();
        return (lv > rv) ? lv : rv;
    }
}

#endif //FUZZY_ORMAX_H

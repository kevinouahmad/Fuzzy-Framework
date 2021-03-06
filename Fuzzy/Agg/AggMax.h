//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_AGGMAX_H
#define FUZZY_AGGMAX_H

#include "../../Core/Expressions/Expression.h"
#include "../../Core/Operators/Agg.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class AggMax : public Agg<T>
    {
    public:
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    T AggMax<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        T lv = left->evaluate();
        T rv = right->evaluate();
        return (lv > rv) ? lv : rv;
    }
}

#endif //FUZZY_AGGMAX_H

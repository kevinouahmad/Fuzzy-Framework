//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_AGGPLUS_H
#define FUZZY_AGGPLUS_H

#include "../../Core/Expressions/Expression.h"
#include "../../Core/Operators/Agg.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class AggPlus : public Agg<T>
    {
    public:
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    T AggPlus<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        return left->evaluate() + right->evaluate();
    }
}

#endif //FUZZY_AGGPLUS_H

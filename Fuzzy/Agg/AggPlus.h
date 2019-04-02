//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_AGGPLUS_H
#define FUZZY_AGGPLUS_H

#include "../../Core/Operators/Then.h"
#include "../../Core/Expressions/Expression.h"

using namespace core;

namespace operators
{
    template <class T>
    class AggPlus : public AggPlus<T>
    {
    public:
        AggPlus();
        virtual ~AggPlus() {};
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    AggPlus<T>::AggPlus() {
    }

    template <class T>
    T AggPlus<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        T lv = left->evaluate();
        T rv = right->evaluate();
        return lv + rv;
    }
}

#endif //FUZZY_AGGPLUS_H

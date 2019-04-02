//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_ORPLUS_H
#define FUZZY_ORPLUS_H

#include "../../Core/Operators/Or.h"
#include "../../Core/Expressions/Expression.h"

using namespace core;

namespace operators
{
    template <class T>
    class OrPlus : public Or<T>
    {
    public:
        OrPlus();
        virtual ~OrPlus() {};
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    OrPlus<T>::OrPlus() {
    }

    template <class T>
    T OrPlus<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        T lv = left->evaluate();
        T rv = right->evaluate();
        return lv + rv;
    }
}

#endif //FUZZY_ORPLUS_H

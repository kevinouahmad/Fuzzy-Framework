//
// Created by Kevin Degraw on 01/04/2019.
//

#ifndef FUZZY_AGGMAX_H
#define FUZZY_AGGMAX_H

#include "Then.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class AggMax : public AggMax<T>
    {
    public:
        AggMax();
        virtual ~AggMax() {};
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    AggMax<T>::AggMax() {
    }

    template <class T>
    T AggMax<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        T lv = left->evaluate();
        T rv = right->evaluate();
        return (lv > rv) ? lv : rv;
    }
}

#endif //FUZZY_AGGMAX_H

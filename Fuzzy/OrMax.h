//
// Created by Kevin Degraw on 01/04/2019.
//

#ifndef FUZZY_ORMAX_H
#define FUZZY_ORMAX_H

#include "Or.h"

using namespace core;

namespace operators
{
    template <class T>
    class OrMax : public Or<T>
    {
    public:
        OrMax();
        virtual ~OrMax() {};
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    OrMax<T>::OrMax() {
    }

    template <class T>
    T OrMax<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        T lv = left->evaluate();
        T rv = right->evaluate();
        return (lv > rv) ? lv : rv;
    }
}

#endif //FUZZY_ORMAX_H

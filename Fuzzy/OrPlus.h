//
// Created by Kevin Degraw on 01/04/2019.
//

#ifndef FUZZY_ORPLUS_H
#define FUZZY_ORPLUS_H

#include "Or.h"

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

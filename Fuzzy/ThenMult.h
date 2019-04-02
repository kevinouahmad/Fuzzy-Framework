//
// Created by Kevin Degraw on 01/04/2019.
//

#ifndef FUZZY_THENMULT_H
#define FUZZY_THENMULT_H

#include "Then.h"

using namespace core;

namespace operators
{
    template <class T>
    class ThenMult : public Or<T>
    {
    public:
        ThenMult();
        virtual ~ThenMult() {};
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    ThenMult<T>::ThenMult() {
    }

    template <class T>
    T ThenMult<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        T lv = left->evaluate();
        T rv = right->evaluate();
        return lv * rv;
    }
}

#endif //FUZZY_THENMULT_H

//
// Created by Kevin Degraw on 01/04/2019.
//

#ifndef FUZZY_THENMIN_H
#define FUZZY_THENMIN_H

#include "Then.h"

using namespace core;

namespace operators
{
    template <class T>
    class ThenMin : public Or<T>
    {
    public:
        ThenMin();
        virtual ~ThenMin() {};
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    ThenMin<T>::ThenMin() {
    }

    template <class T>
    T ThenMin<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        T lv = left->evaluate();
        T rv = right->evaluate();
        return (lv < rv) ? lv : rv;
    }
}

#endif //FUZZY_THENMIN_H

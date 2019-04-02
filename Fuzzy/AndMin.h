//
// Created by Kevin Degraw on 01/04/2019.
//

#ifndef FUZZY_ANDMIN_H
#define FUZZY_ANDMIN_H

#include "And.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class AndMin : public And<T>
    {
    public:
        AndMin();
        virtual ~AndMin() {};
        T evaluate(Expression<T>*, Expression<T>*) const;
    };

    template <class T>
    AndMin<T>::AndMin() {
    }

    template <class T>
    T AndMin<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
        T lv = left->evaluate();
        T rv = right->evaluate();
        return (lv < rv) ? lv : rv;
    }
}

#endif //FUZZY_ANDMIN_H

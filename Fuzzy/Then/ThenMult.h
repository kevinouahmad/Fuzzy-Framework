//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_THENMULT_H
#define FUZZY_THENMULT_H


#include "../../Core/Operators/Or.h"
#include "../../Core/Expressions/Expression.h"

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

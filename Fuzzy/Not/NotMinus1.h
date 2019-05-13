//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_NOTMINUS1_H
#define FUZZY_NOTMINUS1_H

#include "../../Core/Operators/Not.h"

using namespace core;

namespace fuzzy
{
    template <typename T>
    class NotMinus1 : public Not<T> {
    public:
        T evaluate(Expression<T>*) const;
    };

    template <typename T>
    T NotMinus1<T>::evaluate(Expression<T> *expression) const {
        return 1 - expression->evaluate();
    }

}
#endif //FUZZY_NOTMINUS1_H

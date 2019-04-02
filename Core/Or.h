//
// Created by Kevin Degraw on 01/04/2019.
//

#ifndef FUZZY_OR_H
#define FUZZY_OR_H

#include "BinaryExpression.h"

namespace core
{
    template <class T>
    class Or :public BinaryExpression<T>
    {
    public:
        virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
    };
}

#endif //FUZZY_OR_H

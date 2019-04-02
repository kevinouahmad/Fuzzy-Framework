//
// Created by Kevin Degraw on 01/04/2019.
//

#ifndef FUZZY_NOT_H
#define FUZZY_NOT_H

#include "UnaryExpression.h"

namespace core
{
    template <class T>
    class Not :public UnaryExpression<T>
    {
    public:
        virtual T evaluate(Expression<T>*) const = 0;
    };
}

#endif //FUZZY_NOT_H

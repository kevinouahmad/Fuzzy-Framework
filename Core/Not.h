//
// Created by Kevin Degraw on 01/04/2019.
//

#ifndef FUZZY_NOT_H
#define FUZZY_NOT_H

#include "BinaryExpression.h"

namespace core
{
    template <class T>
    class Not :public BinaryExpression<T>
    {
    public:
        virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
    };
}

#endif //FUZZY_NOT_H

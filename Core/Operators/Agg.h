//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_AGG_H
#define FUZZY_AGG_H

#include "../Expressions/Binary/BinaryExpression.h"
#include "../Expressions/Expression.h"

namespace core
{
    template <class T>
    class Agg :public BinaryExpression<T>
    {
    public:
        virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
    };
}

#endif //FUZZY_AGG_H

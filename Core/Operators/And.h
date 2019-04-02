//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_AND_H
#define FUZZY_AND_H

#include "../Expressions/BinaryExpression.h"

namespace core
{
    template <class T>
    class And :public BinaryExpression<T>
    {
    public:
        virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
    };
}

#endif //FUZZY_AND_H

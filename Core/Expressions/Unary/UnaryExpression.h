//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_UNARYEXPRESSION_H
#define FUZZY_UNARYEXPRESSION_H

#include "../Expression.h"

namespace core
{
    template <class T>
    class UnaryExpression
    {
    public:
        virtual T evaluate(Expression<T>*);
    };
}


#endif //FUZZY_UNARYEXPRESSION_H

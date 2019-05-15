//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_IS_H
#define FUZZY_IS_H

#include "../Expressions/Unary/UnaryExpression.h"
#include "../Expressions/Expression.h"

namespace core{

    template <class T>
    class Is : public UnaryExpression<T>
    {
    public:
        virtual T evaluate(Expression<T>*);
    };
}

#endif //FUZZY_IS_H

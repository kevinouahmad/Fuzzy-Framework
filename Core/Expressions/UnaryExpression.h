//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_UNARYEXPRESSION_H
#define FUZZY_UNARYEXPRESSION_H

namespace core
{
    template <class T>
    class UnaryExpression
    {
    public:
        virtual T evaluate(Expression<T>*) const = 0;
    };
}


#endif //FUZZY_UNARYEXPRESSION_H

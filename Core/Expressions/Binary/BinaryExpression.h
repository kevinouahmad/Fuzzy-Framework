//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_BINARYEXPRESSION_H
#define FUZZY_BINARYEXPRESSION_H

namespace core
{
    template <class T>
    class BinaryExpression
    {
    public:
        virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
    };
}

#endif //FUZZY_BINARYEXPRESSION_H

//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_EXPRESSION_H
#define FUZZY_EXPRESSION_H

namespace core
{
    template <class T>
    class Expression {
    public:
        virtual T evaluate() const = 0;
    };
}

#endif //FUZZY_EXPRESSION_H

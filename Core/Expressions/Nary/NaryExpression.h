//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_NARYEXPRESSION_H
#define FUZZY_NARYEXPRESSION_H

#include <vector>
#include "../Expression.h"

namespace core {
    template <typename T>
    class NaryExpression {
    public:
        virtual T evaluate(std::vector<Expression<T>*> *operands) const = 0;
    };
}
#endif //FUZZY_NARYEXPRESSION_H

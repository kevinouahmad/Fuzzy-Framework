//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_MAMDANIDEFUZZ_H
#define FUZZY_MAMDANIDEFUZZ_H

#include "../../Core/Expressions/Binary/BinaryExpression.h"

using namespace core;

namespace fuzzy
{
    template <typename T>
    class MamdaniDefuzz : public BinaryExpression<T> {
        T evaluate(Expression<T>*, Expression<T>*) const = 0;
        virtual T defuzz() const = 0;
    };

}

#endif //FUZZY_MAMDANIDEFUZZ_H

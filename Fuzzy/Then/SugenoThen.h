//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_SUGENOTHEN_H
#define FUZZY_SUGENOTHEN_H

#include "../../Core/Operators/Then.h"

using namespace core;

namespace fuzzy
{
    template <typename T>
    class SugenoThen : public Then<T> {
    public:
        SugenoThen();
        virtual T evaluate(Expression<T>*, Expression<T>*) const;
        virtual T getPremiseValue() const;

    private:
        mutable T premiseValue;
    };

    template <typename T>
    SugenoThen<T>::SugenoThen() : premiseValue(0) {}

    template <typename T>
    T SugenoThen<T>::evaluate(Expression<T> *left, Expression<T> *right) const {
        premiseValue = left->evaluate();
        return premiseValue*right->evaluate();
    }

    template <typename T>
    T SugenoThen<T>::getPremiseValue() const {
        return premiseValue;
    }
}

#endif //FUZZY_SUGENOTHEN_H

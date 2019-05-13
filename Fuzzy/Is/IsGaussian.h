//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_ISGAUSSIAN_H
#define FUZZY_ISGAUSSIAN_H

#include <cmath>
#include "../../Core/Operators/Is.h"

using namespace core;

namespace fuzzy
{
    template <typename T>
    class IsGaussian : public Is<T> {
        IsGaussian(T, T);
        T evaluate(Expression<T>*);

    private:
        T sigma, mu;
    };

    template <typename T>
    IsGaussian<T>::IsGaussian(T _sigma, T _mu) : sigma(_sigma), mu(_mu){}

    template <typename T>
    T IsGaussian<T>::evaluate(Expression<T> *expression) {
        return exp(-0.5 * pow((expression->evaluate() - mu)/sigma, 2))/(sigma*sqrt(6.28));
    }
}

#endif //FUZZY_ISGAUSSIAN_H

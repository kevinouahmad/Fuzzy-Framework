//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_ISTRIANGLE_H
#define FUZZY_ISTRIANGLE_H

#include "../../Core/Operators/Is.h"

using namespace core;

namespace fuzzy
{
    template <typename T>
    class IsTriangle : public Is<T> {
    public:
        IsTriangle(T, T, T);
        T evaluate(Expression<T>*);

    private:
        T start, peak, end;
    };

    template <typename T>
    IsTriangle<T>::IsTriangle(T _start, T _peak, T _end) : start(_start), peak(_peak), end(_end) { }

    template <typename T>
    T IsTriangle<T>::evaluate(Expression<T> *expression) {
        T value = expression->evaluate();
        return (value >= end || value <= start) ? 0 : value >= peak ? (end - value)(end - peak) : (peak - value)/(peak - start);
    }
}

#endif //FUZZY_ISTRIANGLE_H

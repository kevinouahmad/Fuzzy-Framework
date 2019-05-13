//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_ISTRAPEZE_H
#define FUZZY_ISTRAPEZE_H

#include "../../Core/Operators/Is.h"

using namespace core;

namespace fuzzy
{
    template <typename T>
    class IsTrapeze : public Is<T> {
    public :
        IsTrapeze(T, T, T, T);
        T evaluate(Expression<T>*);

    private:
        T start, fstPeak, sndPeak, end;
    };

    template <typename T>
    IsTrapeze<T>::IsTrapeze(T _start, T _fstPeak, T _sndPeak, T _end) : start(_start), fstPeak(_fstPeak), sndPeak(_sndPeak), end(_end) {}

    template <typename T>
    T IsTrapeze<T>::evaluate(Expression<T> *expression) {
        value = expression->evaluate();
        return (value <= start || value >= end) ? 0 : (value >= fstPeak && value <= sndPeak) ? return 1 : (value < fstPeak) ? (value - start)/(fstPeak - start) : (end-value)/(end-sndPeak);
    }

}

#endif //FUZZY_ISTRAPEZE_H

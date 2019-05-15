//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_COGDEFUZZ_H
#define FUZZY_COGDEFUZZ_H

#include "../../Core/Evaluator.h"
#include "MamdaniDefuzz.h"

namespace fuzzy
{
    template <class T>
    class CogDefuzz : public MamdaniDefuzz<T>{
    public:
        CogDefuzz(const T, const T, const T);
        T evaluate(Expression<T>*, Expression<T>*) const;
        T defuzz(const typename Evaluator<T>::Shape&)const;
        typename Evaluator<T>::Shape buildShape(Expression<T>*, Expression<T>*) const;

    private:
        T start;
        T end;
        T step;
    };

    template <class T>
    CogDefuzz<T>::CogDefuzz(const T _start, const T _end, const T _step): start(_start), end(_end), step(_step) {}

    template <typename T>
    T CogDefuzz<T>::evaluate(Expression<T> *left, Expression<T> *right) const {
        return this->defuzz(buildShape(left, right));
    }

    template <class T>
    T CogDefuzz<T>::defuzz(const typename Evaluator<T>::Shape &shape) const
    {
        T num=0, den=0;
        for(unsigned int i = 0; i < shape.first.size(); i++)
        {
            num += shape.first.at(i) * shape.second.at(i);
            den += shape.second.at(i);
        }
        return num/den;
    }

    template <typename T>
    typename Evaluator<T>::Shape CogDefuzz<T>::buildShape(Expression<T> *in, Expression<T> *out) const {
        return Evaluator<T>::buildShape(start, end, step, (ValueModel<T>*)in, out);
    }
}

#endif //FUZZY_COGDEFUZZ_H

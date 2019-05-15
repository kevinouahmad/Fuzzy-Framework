//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef ZRG_EVALUATOR_H
#define ZRG_EVALUATOR_H

#include <vector>
#include"Expressions/Expression.h"
#include"ValueModel.h"

namespace core {
    template<class T>
    class Evaluator {
    public:
        typedef std::pair <std::vector<T>, std::vector<T>> Shape;
        static Shape buildShape(const T &, const T &, const T &, ValueModel<T> *, Expression<T> *);
    };

    template<class T>
    typename Evaluator<T>::Shape
    Evaluator<T>::buildShape(const T &min, const T &max, const T &step, ValueModel<T> *v, Expression<T> *f) {
        std::vector <T> x, y;
        for (T i = min; i <= max; i += step) {
            v->setValue(i);
            y.push_back(f->evaluate());
            x.push_back(i);
        }
        return Shape(x, y);
    }
}

#endif //ZRG_EVALUATOR_H

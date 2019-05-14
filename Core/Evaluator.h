//
// Created by Tistou on 14/05/2019.
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

        static Shape BuildShape(const T &, const T &, const T &, ValueModel<T> *, Expression<T> *);

        static std::ostream &PrintShape(std::ostream &, const Shape &);
    };

    template<class T>
    typename Evaluator<T>::Shape
    Evaluator<T>::BuildShape(const T &min, const T &max, const T &step, ValueModel<T> *v, Expression<T> *f) {
        std::vector <T> x, y;
        for (T i = min; i <= max; i += step) {
            v->setValue(i);
            y.push_back(f->evaluate());
            x.push_back(i);
        }
        return Shape(x, y);
    }

    template<class T>
    std::ostream &Evaluator<T>::PrintShape(std::ostream &os, const Shape &s) {
        os << '[';
        typename vector<T>::const_iterator it = s.first.begin();
        for (; it != s.first.end(); ++it)
            os << *it << ' ';
        os << ']' << endl;
        os << '[';
        it = s.second.begin();
        for (; it != s.second.end(); ++it)
            os << *it << ' ';
        return os << ']' << endl;
    }
}


#endif //ZRG_EVALUATOR_H

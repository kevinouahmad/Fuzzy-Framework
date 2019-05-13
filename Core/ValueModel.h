//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_VALUEMODEL_H
#define FUZZY_VALUEMODEL_H

#include "Expressions/Expression.h"

namespace core
{
    template <class T>
    class ValueModel : public Expression<T>
    {
    public :
        ValueModel(const T&);
        T evaluate() const;
        void setValue(const T&);
        T getValue();

    private:
        T value;
    };

    template <class T>
    ValueModel<T>::ValueModel(const T& _value):
            value(_value)
    {}

    template <class T>
    T ValueModel<T>::evaluate() const
    {
        return value;
    }

    template <class T>
    void ValueModel<T>::setValue(const T& _value)
    {
        value = _value;
    }

    template <typename T>
    T ValueModel<T>::getValue() {
        return value;
    }
}

#endif //FUZZY_VALUEMODEL_H

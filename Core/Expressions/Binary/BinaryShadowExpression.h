//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_BINARYSHADOWEXPRESSION_H
#define FUZZY_BINARYSHADOWEXPRESSION_H

#include "BinaryExpression.h"

namespace core {
    template <typename T>
    class BinaryShadowExpression :public BinaryExpression<T> {
    public:
        BinaryShadowExpression(BinaryExpression<T>* target = nullptr);
        virtual T evaluate(Expression<T>*, Expression<T>*) const;
        BinaryExpression<T>* getTarget() const;
        void setTarget(BinaryExpression<T>*);


    private:
        BinaryExpression<T> *target;
    };

    template <typename T>
    BinaryShadowExpression<T>::BinaryShadowExpression(core::BinaryExpression<T> *_target) : target(_target){}

    template <typename T>
    T BinaryShadowExpression<T>::evaluate(core::Expression<T> *left, core::Expression<T> *right) const {
        if (target != nullptr) {
            return target->evaluate(left, right);
        }
        return NULL;
    }

    template <typename T>
    BinaryExpression<T>* BinaryShadowExpression<T>::getTarget() const {
        return target;
    }

    template <typename T>
    void BinaryShadowExpression<T>::setTarget(core::BinaryExpression<T> *tar) {
        target = tar;
    }



}
#endif //FUZZY_BINARYSHADOWEXPRESSION_H

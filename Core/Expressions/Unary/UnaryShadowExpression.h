//
// Created by Kevin Degraw on 01/04/2019.
//

#ifndef FUZZY_UNARYSHADOWEXPRESSION_H
#define FUZZY_UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"

namespace core {
    template <typename T>
    class UnaryShadowExpression :public UnaryExpression<T> {
    public:
        UnaryShadowExpression(UnaryExpression<T> *target = nullptr);
        virtual T evaluate(Expression<T>*) const;
        UnaryExpression<T>* getTarget() const;
        void setTarget(UnaryExpression<T>*);

    private:
        UnaryExpression<T> *target;
    };

    template <typename T>
    UnaryShadowExpression<T>::UnaryShadowExpression(core::UnaryExpression<T> *_target) : target(_target) {}

    template <typename T>
    T UnaryShadowExpression<T>::evaluate(core::Expression<T> *expression) const {
        if (target != nullptr) {
            return target->evaluate(expression);
        }
        return NULL;
    }

    template <typename T>
    UnaryExpression<T>* UnaryShadowExpression<T>::getTarget() const {
        return target;
    }

    template <typename T>
    void UnaryShadowExpression<T>::setTarget(core::UnaryExpression<T> *_target) {
        target = _target;
    }

}
#endif //FUZZY_UNARYSHADOWEXPRESSION_H

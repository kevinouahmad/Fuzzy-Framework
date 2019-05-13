//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_NARYSHADOWEXPRESSION_H
#define FUZZY_NARYSHADOWEXPRESSION_H

#include "NaryExpression.h"

namespace core {
    template <typename T>
    class NaryShadowExpression : public NaryExpression<T> {
    public:
        NaryShadowExpression(NaryExpression<T> *target = nullptr);

        virtual T evaluate(std::vector<Expression<T>*>*) const;
        NaryExpression<T>* getTarget() const;
        void setTarget(NaryExpression<T>*);

    private:
        NaryExpression<T> *target;
    };

    template <typename T>
    NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T> *_target) : target(_target) {}

    template <typename T>
    T NaryShadowExpression<T>::evaluate(std::vector<core::Expression<T> *> *operands) const {
        if (!operands->empty()) {
            return target->evaluate(operands);
        }
        return NULL;
    }

    template <typename T>
    NaryExpression<T>* NaryShadowExpression<T>::getTarget() const {
        return target;
    }

    template <typename T>
    void NaryShadowExpression<T>::setTarget(core::NaryExpression<T> *_target) {
        target = _target;
    }
}
#endif //FUZZY_NARYSHADOWEXPRESSION_H

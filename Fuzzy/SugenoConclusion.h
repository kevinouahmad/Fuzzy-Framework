//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_SUGENOCONCLUSION_H
#define FUZZY_SUGENOCONCLUSION_H

#include "../Core/Expressions/Nary/NaryExpression.h"

using namespace core;

namespace fuzzy
{
    template <typename T>
    class SugenoConclusion : public NaryExpression<T> {
    public:
        SugenoConclusion(std::vector<T> const&);
        virtual T evaluate(std::vector<Expression<T>*>*) const;

    private:
        const std::vector<T> coeffs;
    };

    template <typename T>
    SugenoConclusion<T>::SugenoConclusion(std::vector<T> const& _coeffs) : coeffs(_coeffs) {}

    template <typename T>
    T SugenoConclusion<T>::evaluate(std::vector<Expression<T> *> *operands) const {
        T out = 0;
        for (auto operand = operands->begin(), coeff = coeffs.begin(); operand != operands->end() && coeff != coeffs.end(); operand++, coeff++) {
            out += (*coeff) * (*operand)->evaluate();
        }
        return out;
    }
}

#endif //FUZZY_SUGENOCONCLUSION_H

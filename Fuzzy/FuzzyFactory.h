//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_FUZZYFACTORY_H
#define FUZZY_FUZZYFACTORY_H

#include "../Core/Expressions/Nary/NaryShadowExpression.h"
#include "../Core/Expressions/Unary/UnaryShadowExpression.h"
#include "../Core/Expressions/Binary/BinaryShadowExpression.h"
#include "../Core/Expressions/Binary/BinaryExpressionModel.h"
#include "../Core/Expressions/ExpressionFactory.h"
#include "../Core/Expressions/Unary/UnaryExpressionModel.h"
#include "../Core/Operators/Is.h"
#include "Defuzz/SugenoDefuzz.h"
#include "SugenoConclusion.h"

namespace fuzzy
{
    template <class T>
    class FuzzyFactory: public ExpressionFactory<T>{
    public:
        FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Is<T>*, Then<T>*, Agg<T>*, MamdaniDefuzz<T>*);
        FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Is<T>*, Then<T>*, Agg<T>*, MamdaniDefuzz<T>*, SugenoDefuzz<T>*, SugenoConclusion<T>*);
        BinaryExpressionModel<T>* newAnd(Expression<T>*, Expression<T>*);
        BinaryExpressionModel<T>* newOr(Expression<T>*,Expression<T>*);
        BinaryExpressionModel<T>* newThen(Expression<T>*,Expression<T>*);
        BinaryExpressionModel<T>* newAgg(Expression<T>*,Expression<T>*);
        BinaryExpressionModel<T>* newDefuzz(Expression<T>*,Expression<T>*);
        UnaryExpressionModel<T>* newNot(Expression<T>*);
        Expression<T>* newIs(core::Is<T>*,Expression<T>*);
        Expression<T>* newSugeno(std::vector<Expression<T>*>*);
        Expression<T>* newConclusion(std::vector<Expression<T>*>*);

        void changeAnd(And<T>*);
        void changeOr(Or<T>*);
        void changeNot(Not<T>*);
        void changeThen(Then<T>*);
        void changeAgg(Agg<T>*);
        void changeIs(Is<T>*);
        void changeSugeno(SugenoDefuzz<T>*);
        void changeConclusion(SugenoConclusion<T>*);

    private :
        UnaryShadowExpression<T>* opNot;
        UnaryShadowExpression<T>* opIs;
        BinaryShadowExpression<T>* opAnd;
        BinaryShadowExpression<T>* opOr;
        BinaryShadowExpression<T>* opThen;
        BinaryShadowExpression<T>* opDefuzz;
        BinaryShadowExpression<T>* opAgg;
        NaryShadowExpression<T>* opSugeno;
        NaryShadowExpression<T>* opConclusion;
    };

    template <class T>
    FuzzyFactory<T>::FuzzyFactory(Not<T> *_opNot, And<T> *_opAnd, Or<T> *_opOr, Is<T> *_opIs, Then<T> *_opThen, Agg<T> *_opAgg , MamdaniDefuzz<T> *_opDefuzz):
        opNot(new UnaryShadowExpression(_opNot)), opAnd(new BinaryShadowExpression(_opAnd)),
        opOr(new BinaryShadowExpression(_opOr)), opIs(new UnaryShadowExpression(_opIs)),
        opThen(new BinaryShadowExpression(_opThen)), opAgg(new BinaryShadowExpression(_opAgg)),
        opDefuzz(new BinaryShadowExpression(_opDefuzz)), opSugeno(NULL), opConclusion(NULL) {}

    template <typename T>
    FuzzyFactory<T>::FuzzyFactory(Not<T> *_opNot, And<T> *_opAnd, Or<T> *_opOr, Is<T> *_opIs, Then<T> *_opThen, Agg<T> *_opAgg, fuzzy::MamdaniDefuzz<T> *_opDefuzz,
                                  fuzzy::SugenoDefuzz<T> *_opSugeno, fuzzy::SugenoConclusion<T> *_opConclusion) :
            opNot(new UnaryShadowExpression(_opNot)), opAnd(new BinaryShadowExpression(_opAnd)),
            opOr(new BinaryShadowExpression(_opOr)), opIs(new UnaryShadowExpression(_opIs)),
                    opThen(new BinaryShadowExpression(_opThen)), opAgg(new BinaryShadowExpression(_opAgg)),
                    opDefuzz(_opDefuzz), opSugeno(_opSugeno),
            opConclusion(_opConclusion) {}

    template <class T>
    BinaryExpressionModel<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r)
    {
        return newBinary(opAnd,l,r);
    }

    template <class T>
    BinaryExpressionModel<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r)
    {
        return newBinary(opOr,l,r);
    }

    template <class T>
    BinaryExpressionModel<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r)
    {
        return new BinaryExpressionModel(opThen,l,r);
    }

    template <class T>
    BinaryExpressionModel<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r)
    {
        return new BinaryExpressionModel(opAgg,l,r);
    }

    template <class T>
    BinaryExpressionModel<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r)
    {
        return new BinaryExpressionModel(opDefuzz,l,r);
    }

    template <class T>
    UnaryExpressionModel<T>* FuzzyFactory<T>::newNot(Expression<T>* o)
    {
        return new UnaryExpressionModel(opNot,o);
    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::newIs(Is<T>* s, Expression<T>* o)
    {
        return newUnary(s,o);
    }

    template <typename T>
    Expression<T>* FuzzyFactory<T>::newSugeno(std::vector<Expression<T> *> *operands) {
        return this->newNary(&opSugeno, operands);
    }

    template <typename T>
    Expression<T>* FuzzyFactory<T>::newConclusion(std::vector<Expression<T> *> *operands) {
        return this->newNary(&opConclusion, operands);
    }

    template <class T>
    void FuzzyFactory<T>::changeAnd(And <T> *o) {
        opAnd->setTarget(o);
    }

    template <class T>
    void FuzzyFactory<T>::changeOr(Or <T> *o) {
        opOr->setTarget(o);
    }

    template <class T>
    void FuzzyFactory<T>::changeThen(Then <T> *o) {
        opThen->setTarget(o);
    }

    template <class T>
    void FuzzyFactory<T>::changeAgg(Agg <T> *o) {
        opAgg->setTarget(o);
    }

    template <class T>
    void FuzzyFactory<T>::changeNot(Not <T> *o) {
        opNot->setTarget(o);
    }

    template<class T>
    void changeIs(Is<T>* o)
    {
        opIs->setTarget(o);
    }

    template<typename T>
    void FuzzyFactory<T>::changeSugeno(SugenoDefuzz<T>* o) {
        opSugeno->setTarget(o);
    }

    template<typename T>
    void FuzzyFactory<T>::changeConclusion(SugenoConclusion<T>* o) {
        opConclusion->setTarget(o);
    }
}

#endif //FUZZY_FUZZYFACTORY_H

//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_FUZZYFACTORY_H
#define FUZZY_FUZZYFACTORY_H


#include "../../Core/Expressions/ExpressionFactory.h"

#include "../Is/IsGaussian.h"

#include "../../Core/Expressions/Unary/UnaryShadowExpression.h"

#include "../../Core/Expressions/Binary/BinaryShadowExpression.h"

namespace fuzzy
{
    template <class T>
    class FuzzyFactory:public ExpressionFactory<T>{
    public:
        FuzzyFactory(UnaryExpression<T>*, BinaryExpression<T>*, BinaryExpression<T>*, BinaryExpression<T>*, BinaryExpression<T>*, BinaryExpression<T>*);
        BinaryExpressionModel<T>* newAnd(Expression<T>*, Expression<T>*);
        BinaryExpressionModel<T>* newOr(Expression<T>*,Expression<T>*);
        BinaryExpressionModel<T>* newThen(Expression<T>*,Expression<T>*);
        BinaryExpressionModel<T>* newAgg(Expression<T>*,Expression<T>*);
        //BinaryExpressionModel<T>* newDefuzz(Expression<T>*,Expression<T>*);
        UnaryExpressionModel<T>* newNot(Expression<T>*);
        Expression<T>* newIs(core::Is<T>*,Expression<T>*);

        void changeAnd(And<T>* o);
        void changeOr(Or<T>* o);
        void changeNot(Not<T>* o);
        void changeThen(Then<T>* o);
        //void changeDefuzz(Defuzz<T>* o);
        void changeAgg(Agg<T>* o);
        void changeIs(Is<T>* o);

    private :
        UnaryShadowExpression<T>* opNot;
        UnaryShadowExpression<T>* opIs;
        BinaryShadowExpression<T>* opAnd;
        BinaryShadowExpression<T>* opOr;
        BinaryShadowExpression<T>* opThen;
        //BinaryShadowExpression<T>* opDefuzz;
        BinaryShadowExpression<T>* opAgg;
};

    template <class T>
    FuzzyFactory<T>::FuzzyFactory(UnaryExpression<T>* _opNot, BinaryExpression<T>* _opAnd, BinaryExpression<T>* _opOr, BinaryExpression<T>* _opThen,BinaryExpression<T>* _opAgg/*,BinaryExpression<T>* _opDefuzz*/):
        opNot(new UnaryShadowExpression<T>(_opNot)),opAnd(new BinaryShadowExpression<T>(_opAnd)),
        opOr(new BinaryShadowExpression<T>(_opOr)),opThen(new BinaryShadowExpression<T>(_opThen)),
        opAgg(new BinaryShadowExpression<T>(_opAgg))/*,opDefuzz(new BinaryShadowExpression<T>(_opDefuzz))*/
    {}

    template <class T>
    BinaryExpressionModel<T>* FuzzyFactory::newAnd(Expression<T>* l, Expression<T>* r)
    {
        return newBinary(opAnd,l,r);
    }

    template <class T>
    BinaryExpressionModel<T>* FuzzyFactory::newOr(Expression<T>* l, Expression<T>* r)
    {
        return newBinary(opOr,l,r);
    }

    template <class T>
    BinaryExpressionModel<T>* FuzzyFactory::newThen(Expression<T>* l, Expression<T>* r)
    {
        return newBinary(opThen,l,r);
    }

    template <class T>
    BinaryExpressionModel<T>* FuzzyFactory::newAgg(Expression<T>* l, Expression<T>* r)
    {
        return newBinary(opAgg,l,r);
    }
/*
    template <class T>
    BinaryExpressionModel<T>* FuzzyFactory::newDefuzz(Expression<T>* l, Expression<T>* r)
    {
        return newBinary(opDefuzz,l,r);
    }*/

    template <class T>
    UnaryExpressionModel<T>* FuzzyFactory::newNot(Expression<T>* o)
    {
        return newUnary(opNot,o);
    }

    template <class T>
    Expression<T>* FuzzyFactory::newIs(Is<T>* s, Expression<T>* o)
    {
        return newUnary(s,o);
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
/*
    template<class T>
    void FuzzyFactory<T>::changeDefuzz(Defuzz<T>* o)
    {
        opDefuzz->setTarget(o);
    }*/

    template<class T>
    void changeIs(Is<T>* o)
    {
        opIs->setTarget(o);
    }
}

#endif //FUZZY_FUZZYFACTORY_H

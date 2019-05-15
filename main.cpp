

#include <iostream>
#include <string>
#include "Core/Operators/Not.h"
#include "Fuzzy/Not/NotMinus1.h"
#include "Fuzzy/And/AndMin.h"
#include "Fuzzy/Or/OrMax.h"
#include "Fuzzy/Then/ThenMin.h"
#include "Fuzzy/Agg/AggMax.h"
#include "Fuzzy/Defuzz/CogDefuzz.h"
#include "Fuzzy/FuzzyFactory.h"
#include "Fuzzy/Is/IsTriangle.h"
#include "Core/ValueModel.h"

using namespace fuzzy;

int main(int argc, char* const argv[]) {
    // operators
    NotMinus1<float> opeNot;
    AndMin<float> opeAnd;
    OrMax<float> opeOr;
    ThenMin<float> opeThen;
    AggMax<float> opeAgg;
    IsTriangle<float> opeIs(0, 10, 4);
    CogDefuzz<float> opDefuzz(0, 25, 1);

    // FuzzyFactory(Not<T> *opNot, And<T> *opAnd, Or<T> *opOr, Then<T> *opThen, Agg<T> *opAgg, MamdaniDefuzz<T> *opDeffuzz);
    FuzzyFactory<float> factory(&opeNot, &opeAnd, &opeOr, &opeIs, &opeThen, &opeAgg, &opDefuzz);

    IsTriangle<float> poor(-5, 0, 5);
    IsTriangle<float> good(0, 5, 10);
    IsTriangle<float> excellent(5, 10, 15);

    IsTriangle<float> cheap(0, 5, 10);
    IsTriangle<float> average(10, 15, 20);
    IsTriangle<float> generous(20, 25, 30);

    ValueModel<float> service(0);
    ValueModel<float> food(0);
    ValueModel<float> tips(0);

    Expression<float> *expr = factory.newAgg(
            factory.newAgg(
                    factory.newThen(factory.newIs(&poor, &service), factory.newIs(&cheap, &tips)),
                    factory.newThen(factory.newIs(&good, &service), factory.newIs( &average, &service))
            ),
            factory.newThen(factory.newIs(&excellent, &service), factory.newIs(&generous, &tips)
            )
    );
    Expression<float> *system = factory.newDefuzz(&tips, expr);

    float s;
    while (true) {
        std::cout << "Service : ";
        std::cin >> s;
        service.setValue(s);
        std::cout << "Tips -> " << system->evaluate() << std::endl;
    }
}


#include <iostream>
#include <string>

using namespace std;
using namespace core;
using namespace operators;

int main(int argc, _TCHAR *argv[]) {
    NotMinus1<double> opNot;
    AndMin<double> opAnd;
    OrMax<double> opOr;
    ThenMin<double> opThen;
    AggMax<double> opAgg;
    CogDefuzz<double> opDefuzz(0, 40, 1);

    FuzzyFactory<double> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);

    double minMauvais = 0;
    double midMauvais = 10;
    double maxMauvais = 20;
    IsTriangle<double> mauvais(minMauvais, midMauvais, maxMauvais);

    double minMoyen = 10;
    double midMoyen = 20;
    double maxMoyen = 30;
    IsTriangle<double> moyen(minMoyen, midMoyen, maxMoyen);

    double minBon = 20;
    double midBon = 30;
    double maxBon = 40;
    IsTriangle<double> bon(minBon, midBon, maxBon);

    double minMauvaises = 0;
    double midMauvaises = 10;
    double maxMauvaises = 20;
    IsTriangle<double> mauvaises(minMauvaises, midMauvaises, maxMauvaises);

    double minMoyennes = 10;
    double midMoyennes = 20;
    double maxMoyennes = 30;
    IsTriangle<double> moyennes(minMoyennes, midMoyennes, maxMoyennes);

    double minBonnes = 20;
    double midBonnes = 30;
    double maxBonnes = 40;
    IsTriangle<double> bonnes(minBonnes, midBonnes, maxBonnes);


    ValueModel<double> scenario(0);
    ValueModel<double> critiques(0);


    Expression<double> *r =
            f.newAgg(
                    f.newAgg(
                            f.newThen(
                                    f.newIs(&mauvais, &scenario),
                                    f.newIs(&mauvaises, &critiques)
                            ),
                            f.newThen(
                                    f.newIs(&moyen, &scenario),
                                    f.newIs(&moyennes, &critiques)
                            )
                    ),
                    f.newThen(
                            f.newIs(&bon, &scenario),
                            f.newIs(&bonnes, &critiques)
                    )
            );

    Expression<double> *system = f.newDefuzz(&critiques, r);

    double s;
    while (true) {
        cout << "scenario :";
        cin >> s;
        scenario.setValue(s);
        cout << "critiques ->" << system->evaluate() << endl;
    }

}
//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_MAMDANIDEFUZZ_H
#define FUZZY_MAMDANIDEFUZZ_H

namespace fuzzy
{
    template <class T>
            class MamdaniDefuzz : public BinaryExpression(<T>){
            public:
                MamdaniDefuzz(const T&, const T&, const T&);

                T evaluate(Expression<T>* _l,Expression<T>* _r) const;
                virtual T defuzz(const typename Evaluator<T>::Shape&) const=0;

            private:
                T min,max,step,current;
            };

    template <class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(const T& _min,const T& _max,const T& _step):
    min(_min),max(_max),step(_step)
    {}

    template <class T>
    T MamdaniDefuzz<T>::evaluate(Expression<T>* s, Expression<T>* var) const{
        return defuzz(Evaluator<T>::BuildShape(min,max,step,(ValueModel<T>*)s,var));
    }
}

#endif //FUZZY_MAMDANIDEFUZZ_H

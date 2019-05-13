//
// Created by Kevin Ouahmad | Florian Carlier | Baptiste Leclerc on 01/04/2019.
//

#ifndef FUZZY_COGDEFUZZ_H
#define FUZZY_COGDEFUZZ_H

namespace fuzzy
{
    template <class T>
    class CogDefuzz : public MamdaniDefuzz<T>{
    public:
        CogDefuzz(const T&, const T&, const T&);
        T defuzz(const typename Evaluator<T>::Shape&)const;
    };

    template <class T>
    CogDefuzz<T>::CogDefuzz(const T& _min, const T& _max, const T& _step):
    MamdaniDefuzz(_min,_max,_step)
    {}

    template <class T>
    T CogDefuzz<T>::defuzz(const typename Evaluator<T>::Shape &s) const
    {
        T x,y,num=0,den=0;
        for(unsigned int i=0;i<(s.first.size()-1);i++)
        {
            x=s.first.at(i);
            y=s.second.at(i);
            num+=x*y;
            den+=y;
        }
        return num/den
    }
}

#endif //FUZZY_COGDEFUZZ_H

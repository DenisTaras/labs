#ifndef Linefom_hpp
#define Linefom_hpp
#include "Sequence.hpp"

template<typename T>
class Lineform{
    public:
    Lineform<T>(int size) : data(size) {}

    Lineform<T>(const Lineform<T> &polinom) : data(polinom.data){}

    int GetSize(){
        return data.GetLength();
    }
       void Set(int i, T item) {
        data.Set(i, item);
    }
    T Get(int i){
        return data.Get(i);
    }
    static int compare(Lineform<T>& P1, Lineform<T>& P2){
        if(P1.GetSize() == P2.GetSize()){
            for (int i = 0; i < P1.GetSize(); i++){
                if(!(P1.Get(i) == P2.Get(i))){
                    return 0;
                }
            }
            return 1;
        }
        else return 0;
    }

    static Lineform<T> sum(Lineform<T>& P1, Lineform<T>& P2){
        Lineform<T> P3 = Lineform<T>(std::max(P1.GetSize(),P2.GetSize()));
        if(P1.GetSize() >= P2.GetSize()){
            for(int i = 0; i < P2.GetSize() ; i++){
                P3.Set(i, P1.Get(i)+P2.Get(i));
            }
            for(int i = P2.GetSize();i<P1.GetSize() ;i++){
                P3.Set(i, P1.Get(i));
            }
        }
        else{
            for(int i = 0; i < P1.GetSize(); i++){
                P3.Set(i, P1.Get(i)+P2.Get(i));
            }
            for(int i = P1.GetSize();i<P2.GetSize();i++){
                P3.Set(i, P2.Get(i));
            }
        }
        return P3;
    }
    static void scalar(Lineform<T> &P1, T a){
        for(int i = 0; i< P1.GetSize();i++){
            P1.Set(i, P1.Get(i)*a);
        }
    }
    T value(Lineform<T>& t){
        T sum = 0;
        for(int i = 0; i < GetSize() ;i++){
            sum +=Get(i)*t.Get(i);
        }
        return sum;
    }
    private:
    ArraySequence<T> data;
};
template <typename T>
std::ostream & operator << (std::ostream & out, Lineform<T> a){
    for(int i = 0; i < a.GetSize();++i){
        out << a.Get(i) << " ";
    }
    return out;
}
template <typename T>
std::istream & operator >> (std::istream & in, Lineform<T>& a){
    for(int i = 0; i < a.GetSize();i++){
        T q;
        in >> q;
        a.Set(i,q);
    }
    return in;
}
template <typename T>
Lineform<T> operator + (Lineform<T>& a, Lineform<T>& b){
    return Lineform<T>::sum(a,b);
}
template <typename T>
Lineform<T> operator - (Lineform<T>& a, Lineform<T> b){
    return Lineform<T>::sum(a, b*= T(-1));
}
template<typename T>
Lineform<T> operator *= (Lineform<T> &a,T b){
    Lineform<T>::scalar(a,b);
    return a;
}

#endif
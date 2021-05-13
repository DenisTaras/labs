#ifndef Polinomial_hpp
#define Polinomial_hpp
#include "Sequence.hpp"

template<typename T>
class Polinomial{
    public:
    Polinomial<T>(int size){
        data =ArraySequence<T>(size);
    }
    Polinomial<T>(const Polinomial<T> &polinom){
        data = ArraySequence<T>(polinom.data);
    }
    int GetSize(){
        return data.GetLength();
    }
    void Delete(){
        data.Delete();
    }



    static Polinomial<T> sum(Polinomial<T> P1, Polinomial<T> P2){
        Polinomial<T> P3 = Polinomial<T>(std::max(P1.GetSize(),P2.GetSize()));
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
    static Polinomial<T> composition(Polinomial<T> P1, Polinomial<T> P2){
        Polinomial<T> P3 = Polinomial<T>(P1.GetSize() + P2.GetSize() - 1);
        for(int i = 0; i < P1.GetSize();i++){
            for(int j = 0; j < P2.GetSize() ;j++){
                P3.Set(i+j, P1.Get(i)*P2.Get(j));
            }
        }
        return P3;
    }
    static void scalar(Polinomial<T> &P1, T a){
        for(int i = 0; i< P1.GetSize();i++){
            P1.Set(i, P1.Get(i)*a);
        }
    }
    T gorner(T t){
        T sum = 0;
        for(int i = GetSize() - 1; i >= 1 ;i--){
            sum +=Get(i);
            sum *=t;
        }
        sum +=Get(0);
        return sum;
    }
    void Set(int i, T item) {
        data.Set(i, item);
    }
    T Get(int i){
        return data.Get(i);
    }
    private:
    ArraySequence<T> data;
};

template <typename T>
std::ostream & operator << (std::ostream & out, Polinomial<T> a){
    for(int i = 0; i < a.GetSize();++i){
        out << a.Get(i) << " ";
    }
    return out;
}

template <typename T>
std::istream & operator >> (std::istream & in, Polinomial<T>& a){
    T q;
    for(int i = 0; i < a.GetSize();i++){
        in >> q;
        a.Set(i,q);
    }
    return in;
}
template <typename T>
Polinomial<T> operator + (Polinomial<T> a, Polinomial<T> b){
    return Polinomial<T>::sum(a,b);
}
template<typename T>
Polinomial<T> operator *= (Polinomial<T> &a,T b){
    Polinomial<T>::scalar(a,b);
    return a;
}

template<typename T>
Polinomial<T> operator * (Polinomial<T> a, Polinomial<T> b){
    return Polinomial<T>::composition(a,b);
}
#endif
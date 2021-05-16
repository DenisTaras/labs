#ifndef tests_hpp
#define tests_hpp
#include <iostream>
#include <fstream>
#include "Polinomial.hpp"
#include "Array.hpp"
#include "List.hpp"
#include "Lineform.hpp"
class tests
{
public:
    template<typename T>
   static void testsumP(const char* filename){

    std::ifstream in(filename);
    int counttest;
    in >> counttest;
    for(int n = 0; n < counttest; n++){
        int deg1, deg2, degTrue;
        in >> deg1;
        Polinomial<T> P1(deg1 +1);
        in >> P1;
        in >> deg2;
        Polinomial<T> P2(deg2 +1);
        in >> P2;
        Polinomial<T> P3 = P1 + P2;
        in >> degTrue;
        Polinomial<T> PTrue(degTrue +1);
        in >> PTrue;
        int qww = Polinomial<T>::compare(P3, PTrue);
        if(!qww){
            std::cout << " EROOR in "<< n <<" test form testsum.\n";
        }
        //std::cout<<"P1: "<< P1;
        //std::cout<<"P2: "<< P2;
        //std::cout<<"P3: "<< P3;
        //std::cout<<"Ptrue: "<< PTrue << "\n";
        //P1.Delete();
        P2.Delete();
        P3.Delete();
        PTrue.Delete();
    }
   }
    template<typename T>
    static void testcompP( const char* filename){

    std::ifstream in( filename);
    int counttest;
    in >> counttest;
    for(int n = 0; n < counttest; n++){
        int deg1, deg2, degTrue;
        in >> deg1;
        Polinomial<T> P1(deg1 +1);
        in >> P1;
        in >> deg2;
        Polinomial<T> P2(deg2 +1);
        in >> P2;
        Polinomial<T> P3 = P1 * P2;
        in >> degTrue;
        Polinomial<T> PTrue(degTrue +1);
        in >> PTrue;
        int qww = Polinomial<T>::compare(P3, PTrue);
        if(!qww){
            std::cout << " EROOR in "<< n <<" test form testcomp.\n";
        }
       // std::cout<<"P1: "<< P1;
        //std::cout<<"P2: "<< P2;
        //std::cout<<"P3: "<< P3;
        //std::cout<<"Ptrue: "<< PTrue << "\n";
        P1.Delete();
        P2.Delete();
        P3.Delete();
        PTrue.Delete();
    }
   }

    template<typename T>
    static void testscalarP(const char* filename){
    std::ifstream in( filename);
    int counttest;
    in >> counttest;
    for(int n = 0; n < counttest; n++){
        int deg1, degTrue;
        T scalar;
        in >> deg1;
        Polinomial<T> P1(deg1 +1);
        in >> P1;
        in >> scalar;
        P1*= scalar;
        in >> degTrue;
        Polinomial<T> PTrue(degTrue +1);
        in >> PTrue;
        int qww = Polinomial<T>::compare(P1, PTrue);
        if(!qww){
            std::cout << " EROOR in "<< n <<" test form testscalar.\n";
        }
      //  std::cout<<"P1: "<< P1;
        //std::cout<<"Ptrue: "<< PTrue << "\n";
        P1.Delete();
        PTrue.Delete();
    }
   }

       template<typename T>
    static void testgornerP(const char* filename){
    std::ifstream in( filename);
    int counttest;
    in >> counttest;
    for(int n = 0; n < counttest; n++){
        int deg1;
        T scalar, value, valueTrue;
        in >> deg1;
        Polinomial<T> P1(deg1 +1);
        in >> P1;
        in >> scalar;
        value = P1.gorner(scalar);
        in >> valueTrue;
        int qww = (value == valueTrue);
        if(!qww){
            std::cout << " EROOR in "<< n <<" test form testgorner.\n";
        }
    //    std::cout<<"P1: "<< P1;
     //   std::cout<<"valueTrue: "<< valueTrue << "\n";
        P1.Delete();
    }
   }

        template<typename T>
    static void testvalueL(const char* filename){
    std::ifstream in( filename);
    int counttest;
    in >> counttest;
    for(int n = 0; n < counttest; n++){
        int deg1;
        T value, valueTrue;
        in >> deg1;
        Lineform<T> P1(deg1);
        in >> P1;
        Lineform<T> vector(deg1);
        in >> vector;
        value = P1.value(vector);
         in >> valueTrue;
        int qww = (value == valueTrue);
        if(!qww){
            std::cout << " EROOR in "<< n <<" test form testvalueL. \n";
        }
      //  std::cout<<"P1: "<< P1;
    //    std::cout<<"valueTrue: "<< valueTrue << "\n";
        P1.Delete();
        vector.Delete();
        }
    }
        template<typename T>
   static void testsumL( const char* filename){
           std::ifstream in(filename);
    int counttest;
    in >> counttest;
    for(int n = 0; n < counttest; n++){
        int deg1, deg2, degTrue;
        in >> deg1;
        Lineform<T> P1(deg1 + 1);
        in >> P1;
        in >> deg2;
        Lineform<T> P2(deg2 + 1);
        in >> P2;
        Lineform<T> P3 = P1 + P2;
        in >> degTrue;
        Lineform<T> PTrue(degTrue + 1);
        in >> PTrue;
        int qww = Lineform<T>::compare(P3, PTrue);
        if(!qww){
            std::cout << " EROOR in "<< n <<" test form testsumL.\n";
        }
      //  std::cout<<"P1: "<< P1;
    //    std::cout<<"P2: "<< P2;
      //  std::cout<<"P3: "<< P3;
       // std::cout<<"Ptrue: "<< PTrue << "\n";
        P1.Delete();
        P2.Delete();
        P3.Delete();
        PTrue.Delete();
    }
   }

template<typename T>
    static void testscalarL(const char* filename){
    std::ifstream in( filename);
    int counttest;
    in >> counttest;
    for(int n = 0; n < counttest; n++){
        int deg1, degTrue;
        T scalar;
        in >> deg1;
        Lineform<T> P1(deg1 +1);
        in >> P1;
        in >> scalar;
        P1*= scalar;
        in >> degTrue;
        Lineform<T> PTrue(degTrue +1);
        in >> PTrue;
        int qww = Lineform<T>::compare(P1, PTrue);
        if(!qww){
            std::cout << " EROOR in "<< n <<" test form testscalar.\n";
        }
     //   std::cout<<"P1: "<< P1;
       // std::cout<<"Ptrue: "<< PTrue << "\n";
        P1.Delete();
        PTrue.Delete();
    }
   }

    template<typename T>
    static void testconcatArr(const char* filename){
    std::ifstream in(filename);
    int counttest;
    in >> counttest;
    for(int n = 0; n < counttest; n++){
        int deg1, deg2, degTrue;
        in >> deg1;
        ArraySequence<T> P1(deg1 +1);
        in >> P1;
        in >> deg2;
        ArraySequence<T> P2(deg2 +1);
        in >> P2;
        ArraySequence<T> P3 = *P1.Concat(&P2);
        in >> degTrue;
        ArraySequence<T> PTrue(degTrue +1);
        in >> PTrue;
        int qww = ArraySequence<T>::compare(P3, PTrue);
        if(!qww){
            std::cout << " EROOR in "<< n <<" test form testconcatArr.\n";
        }
    //    std::cout<<"P1: "<< P1;
     //   std::cout<<"P2: "<< P2;
     //   std::cout<<"P3: "<< P3;
      //  std::cout<<"Ptrue: "<< PTrue << "\n";
        P1.Delete();
        P2.Delete();
        P3.Delete();
        PTrue.Delete();
    }
   }

       template<typename T>
    static void testsubArr(const char* filename){
    std::ifstream in(filename);
    int counttest;
    in >> counttest;
    for(int n = 0; n < counttest; n++){
        int deg1, stin, lsin, degTrue;
        in >> deg1 >> stin >> lsin;
        ArraySequence<T> P1(deg1 +1);
        in >> P1;
        ArraySequence<T> P3 = *P1.GetSubsequence(stin,lsin);
        in >> degTrue;
        ArraySequence<T> PTrue(degTrue +1);
        in >> PTrue;
        int qww = ArraySequence<T>::compare(P3, PTrue);
        if(!qww){
            std::cout << " EROOR in "<< n <<" test form testsubArr.\n";
        }
     //   std::cout<<"P1: "<< P1;
      //  std::cout<<"P3: "<< P3;
      //  std::cout<<"Ptrue: "<< PTrue << "\n";
        P1.Delete();
        P3.Delete();
        PTrue.Delete();
    }
   }

       template<typename T>
    static void testconcatList(const char* filename){
    std::ifstream in(filename);
    int counttest;
    in >> counttest;
    for(int n = 0; n < counttest; n++){
        int deg1, deg2, degTrue;
        T qqq;
        in >> deg1;
        LinkedListSequence<T> P1;
        for(int i = 0; i < deg1 + 1; i++){
            in >> qqq;
            P1.Append(qqq);
        }
    //    std::cout<<"P1: "<< P1;
        in >> deg2;
        LinkedListSequence<T> P2;
        for(int i = 0; i < deg2 + 1; i++){
            in >> qqq;
            P2.Append(qqq);
        }
     //   std::cout<<"P2: "<< P2;
        LinkedListSequence<T> P3 = *P1.Concat(&P2);
    //    std::cout<<"P3: "<< P3;
        in >> degTrue;
        LinkedListSequence<T> PTrue;
        for(int i = 0; i < degTrue + 1; i++){
            in >> qqq;
            PTrue.Append(qqq);
        }
        int qww = LinkedListSequence<T>::compare(P3, PTrue);
        if(!qww){
            std::cout << " EROOR in "<< n <<" test form testconcatArr.\n";
        }
    //    std::cout<<"P1: "<< P1;
    //    std::cout<<"P2: "<< P2;
    //    std::cout<<"P3: "<< P3;
    //    std::cout<<"Ptrue: "<< PTrue << "\n";

    }
   }

          template<typename T>
    static void testsubList(const char* filename){
    std::ifstream in(filename);
    int counttest;
    in >> counttest;
    for(int n = 0; n < counttest; n++){
        int deg1, stin, lsin, degTrue;
        T qqq;
        in >> deg1 >> stin >> lsin;
        LinkedListSequence<T> P1;
        for(int i = 0; i < deg1 + 1; i++){
            in >> qqq;
            P1.Append(qqq);
        };
        LinkedListSequence<T> P3 = *P1.GetSubsequence(stin -1,lsin -1);
        in >> degTrue;
        LinkedListSequence<T> PTrue;
        for(int i = 0; i < degTrue + 1; i++){
            in >> qqq;
            PTrue.Append(qqq);
        }
        int qww = LinkedListSequence<T>::compare(P3, PTrue);
        if(!qww){
            std::cout << " EROOR in "<< n <<" test form testsubList.\n";
        }
      //  std::cout<<"P1: "<< P1;
      //  std::cout<<"P3: "<< P3;
      //  std::cout<<"Ptrue: " << PTrue << "\n";
    }
   }

};
#endif
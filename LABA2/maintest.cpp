#include<iostream>
#include "tests.hpp"
#include "Polinomial.hpp"
#include "Sequence.hpp"
#include <complex>
int main(){
    double x = 1;
    std::cout<<"Tests started\n";
    tests::testsum<double>("tests/sum");
    std::cout<<"Tests sum ended\n";
    tests::testcomp<double>("tests/comp");
    std::cout<<"Tests testcomp ended\n";
    tests::testscalar<double>("tests/scalar");
    std::cout<<"Tests testscalar ended\n";
    tests::testgorner<double>("tests/gorner");
    std::cout<<"Tests testgorner ended\n";
    std::cout<<"Tests ended\n";
    tests::testsubArr<double>("tests/sub");
    std::cout<<"Tests testsubArr ended\n";
    tests::testconcatArr<double>("tests/concat");
    std::cout<<"Tests concatArr ended\n";
    tests::testconcatList<double>("tests/concat");
    std::cout<<"Tests concatList ended\n";
    return 0;
}
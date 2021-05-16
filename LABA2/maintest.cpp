#include<iostream>
#include "tests.hpp"
#include "Polinomial.hpp"
#include "Sequence.hpp"
#include <complex>
int main(){
    std::cout<<"Tests started\n";
    tests::testsumP<double>("tests/sum");
    tests::testsumP<std::complex<double>>("tests/sumC");
    std::cout<<"Tests sumP ended\n";
    tests::testsumL<double>("tests/sum");
    tests::testsumL<std::complex<double>>("tests/sumC");
    std::cout<<"Tests sumL ended\n";
    tests::testcompP<double>("tests/comp");
    tests::testcompP<std::complex<double>>("tests/compC");
    std::cout<<"Tests testcomp ended\n";
    tests::testscalarP<double>("tests/scalar");
    tests::testscalarP<std::complex<double>>("tests/scalarC");
    std::cout<<"Tests testscalar ended\n";
    tests::testscalarL<double>("tests/scalar");
    tests::testscalarL<std::complex<double>>("tests/scalarC");
    std::cout<<"Tests testscalarL ended\n";
    tests::testgornerP<double>("tests/gorner");
    tests::testgornerP<std::complex<double>>("tests/gorner");
    std::cout<<"Tests testgorner ended\n";
    tests::testvalueL<double>("tests/valueL");
    std::cout<<"Tests testvalueL ended\n";
    tests::testsubArr<double>("tests/sub");
    std::cout<<"Tests testsubArr ended\n";
    tests::testconcatArr<double>("tests/concat");
    std::cout<<"Tests concatArr ended\n";
    tests::testconcatList<double>("tests/concat");
    std::cout<<"Tests concatList ended\n";
    tests::testsubList<double>("tests/sub");
    std::cout<<"Tests testsubList ended\n";
    std::cout<<"Tests ended\n";
    return 0;
}
#ifndef polynomial_h
#define polynomial_h
#include "vector.h"
#include <complex.h>
vector* sumZ(vector* p1,vector* p2);
vector* compositionZ(vector* p1,vector* p2);
void scalarZ(vector* p1,int a);
int gornerZ(vector* p1, int t);
vector* sumC(vector* p1,vector* p2);
vector* compositionC(vector* p1,vector* p2);
void scalarC(vector* p1,double complex a);
double complex gornerC(vector* p1, double complex t);
void printZ(vector*);
void printC(vector* P);
#endif
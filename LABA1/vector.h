#ifndef vector_h
#define vector_h
#include <stdlib.h>
#include <string.h>
 typedef struct vector
 {
     void * head;
     int len;
     int size;
 }vector;
 vector* create(int);
 void del(vector*);
 void push(vector* pu,void* data, int count);
 
 #endif
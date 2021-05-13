#include "polynomial.h"
#include <stdio.h>
vector* sumZ(vector* p1,vector* p2){
    if(p1->len > p2->len){
        vector* p3 = create (p1->size);
        p3->len=p2->len;
        p3->head=(int*)calloc(p2->len,p2->size);
        for(int i = 0;i< p2->len;i++){
            *((int*)(p3->head) + i)=*((int*)(p1->head) + i)+*((int*)(p2->head) + i);
        }
        push(p3, (int*)p1->head +  p2->len, p1->len - p2->len);
        return p3;
    }
    if(p1->len < p2->len){
        vector* p3 = create (p2->size);
        p3->head=(int*)calloc(p1->len,p1->size);
        p3->len=p1->len;
        for(int i = 0;i < p1->len;i++){
            *((int*)(p3->head) + i)=*((int*)(p2->head) + i)+*((int*)(p1->head) + i);
        }
        push(p3, (int*)p2->head +  p1->len, p2->len - p1->len);
        return p3;
    }
    if(p1->len == p2->len){
        vector* p3 = create (p2->size);
        p3->head=(int*)calloc(p1->len,p1->size);
        p3->len=p2->len;
        for(int i = 0;i < p1->len;i++){
            ((int*)(p3->head))[i]=*((int*)(p2->head) + i)+*((int*)((*p1).head) + i);
        }
        return p3;}
}
vector* compositionZ(vector* p1,vector* p2){
    vector* p3 = create (p1->size);
    p3->head=(int*)calloc(p1->len+p2->len - 1,p1->size);
    for(int i = 0; i < p1->len; i++){
        for(int j=0;j < p2->len; j++){
            ((int*)p3->head)[i + j] += ((int*)p2->head)[j] * ((int*)p1->head)[i];
        }
    }
    p3->len=p1->len+p2->len - 1;
    return p3;
}
void scalarZ(vector* p1,int a){
    for(int i = 0; i < p1->len; i++){
         ((int*)p1->head)[i]*=a;
    }
}
int gornerZ(vector* p1, int t){
    int sum = 0;
    for (int i = p1->len - 1; i > 0; i--){
        sum +=  ((int*)p1->head)[i];
        sum*=t;
    }
    sum+= *((int*)p1->head);
    return sum;
}
vector* sumC(vector* p1,vector* p2){
    if(p1->len > p2->len){
        vector* p3 = create (p1->size);
        p3->len=p2->len;
        p3->head=(double complex*)calloc(p2->len,p2->size);
        for(int i = 0;i< p2->len;i++){
            ((double complex*)p3->head)[i] = ((double complex*)p1->head)[i] + ((double complex*)p2->head)[i];
        }  
        push(p3, (double complex *)p1->head +  p2->len, p1->len - p2->len);
        return p3;
    }
    if(p1->len < p2->len){
        vector* p3 = create (p2->size);
        p3->head=(double complex*)calloc(p1->len,p1->size);
        p3->len=p1->len;
        for(int i = 0;i < p1->len;i++){
            *((double complex*)(p3->head) + i)=*((double complex*)(p2->head) + i)+*((double complex*)(p1->head) + i);
        }
        push(p3, (double complex *)p2->head +  p1->len, p2->len - p1->len);
        return p3;
    }
    if(p1->len == p2->len){
        vector* p3 = create (p2->size);
        p3->head=(double complex*)calloc(p1->len,p1->size);
        p3->len=p2->len;
        for(int i = 0;i < p1->len;i++){
            *((double complex*)(p3->head) + i)=*((double complex*)(p2->head) + i)+*((double complex*)(p1->head) + i);
        }
        return p3;
        }
}
vector* compositionC(vector* p1,vector* p2){
    vector* p3 = create (p1->size);
    p3->head=(double complex*)calloc(p1->len+p2->len - 1,p1->size);
    for(int i = 0; i < p1->len; i++){
        for(int j=0;j < p2->len; j++){
            ((double complex*)p3->head)[i + j] += ((double complex*)p2->head)[j] * ((double complex*)p1->head)[i];
        }
    }
    p3->len=p1->len+p2->len - 1;
    return p3;
}
void scalarC(vector* p1,double complex a){
    for(int i = 0; i < p1->len; i++){
         ((double complex*)p1->head)[i]*=a;
    }
}
double complex gornerC(vector* p1, double complex t){
    double complex sum = 0;
    for (int i = p1->len - 1; i > 0; i--){
        sum +=  ((double complex*)p1->head)[i];
        sum*=t;
    }
    sum+= *((double complex*)p1->head);
    return sum;
}
void printZ(vector* P){
    int i;
    for(i = 0; i < P->len - 1;i++){
        printf("%d*X^%d + ", ((int*)P->head)[i],i);
    }
    printf("%d*X^%d\n", ((int*)P->head)[i],i);
}
void printC(vector* P){
    int i;
    for(i = 0; i < P->len - 1;i++){
        printf("(%lf + %lf * I))*X^%d + ", creal(((double complex*)P->head)[i]), cimag(((double complex *)P->head)[i]),i);
    }
    printf("(%lf + %lf * I))*X^%d\n", creal(((double complex*)P->head)[i]),cimag(((double complex*)P->head)[i]) ,i);
}

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "polynomial.h"

const char * MSG[] = {"1.EXIT", "2.Enter Polynomial (in integer)", "3. Enter Polynomial (in complex)", "4. Sum", "5. Composition" , "6. Scalar" , "7. Value", "8. Print list"};
const int SMSG = 8;
int getmenu() {
    char * error = "";
    int ch = 0;
    do {
        puts(error);
        error = "You're wrong. Try again!";
        for (int i = 0; i < SMSG; i++) {
        puts(MSG[i]);
        }
        puts("Make your choice: ");
        ch = getchar() - '0';
        while (getchar() != '\n') {}    
    } while(ch < 1 || ch > SMSG);
    
    return ch;
}
int main(){
    int turn = 1;
    int res = 0;
    vector** PolynomsZ = NULL;
    vector** PolynomsC = NULL;
    int countC = 0;
    int countZ = 0;
    while(turn) {
        res = getmenu();
        switch(res) {
            case 1: {
                printf("Goodbye");
                turn  = 0;
                break;
            }
            case 2:{
                PolynomsZ = (vector **)realloc(PolynomsZ, (countZ+1)*sizeof(vector*));
                PolynomsZ[countZ] = create(sizeof(int));
                printf("Enter degree\n");
                int degree;
                scanf("%d", &degree );
                printf("Enter factors\n");
                int* q = calloc(degree+1,sizeof(int));
                for(int i = 0; i < degree +1; i++){
                    scanf("%d", q+i);
                }
                printf("Thanks\n");
                push(PolynomsZ[countZ], q, degree + 1);
                free(q);
                countZ++;
                scanf("%*c");
                break;
            }
            case 3:{
                PolynomsC= (vector **)realloc(PolynomsC, (countC+1)*sizeof(vector*));
                PolynomsC[countC]=create(sizeof(double complex));
                printf("Enter degree\n");
                int degree;
                scanf("%d", &degree );
                printf("Enter factors\n");
                double complex * q = calloc(degree+1,sizeof(double complex));
                double re,im;
                for(int i = 0; i < degree +1; i++){
                    scanf("%lf %lf", &re, &im);
                    __real__ q[i] = re;
                    __imag__ q[i] = im;
                }
                printf("Thanks\n");
                push(PolynomsC[countC],q,degree + 1);
                free(q);
                countC++;
                scanf("%*c");
                break;
            }
            case 4:{ 
                printf("Choose type:\n 1.Integer\n 2.Complex\n");
                int choose;
                scanf("%d",&choose);
                switch(choose){
                    case 1: {
                        PolynomsZ = (vector **)realloc(PolynomsZ, (countZ+1)*sizeof(vector*));
                        int NUM1,NUM2;
                        printf("Enter NUM1\n");
                        scanf("%d",&NUM1);
                        printf("Enter NUM2\n");
                        scanf("%d",&NUM2);
                        PolynomsZ[countZ] = sumZ(PolynomsZ[NUM1],PolynomsZ[NUM2]);
                        printf("Sum result: ");
                        printZ(PolynomsZ[countZ]);
                        countZ++;
                        break;
                    }
                    case 2:{
                        PolynomsC= (vector **)realloc(PolynomsC, (countC+1)*sizeof(vector*));
                        int NUM1,NUM2;
                        printf("Enter NUM1\n");
                        scanf("%d",&NUM1);
                        printf("Enter NUM2\n");
                        scanf("%d",&NUM2);
                        PolynomsC[countC] = sumC(PolynomsC[NUM1],PolynomsC[NUM2]);
                        printf("Sum result: ");
                        printC(PolynomsC[countC]);
                        countC++;
                        break;
                    }
                }
                scanf("%*c");
                break;
            }
            case 5:{
                printf("Choose type:\n 1.Integer\n 2.Complex\n");
                int choose;
                scanf("%d",&choose);
                switch(choose){
                    case 1: {
                        int NUM1,NUM2;
                        printf("Enter NUM1\n");
                        scanf("%d",&NUM1);
                        printf("Enter NUM2\n");
                        scanf("%d",&NUM2);
                        PolynomsZ = (vector **)realloc(PolynomsZ, (countZ+1)*sizeof(vector*));
                        PolynomsZ[countZ] = compositionZ(PolynomsZ[NUM1],PolynomsZ[NUM2]);
                        printf("Composition result: ");
                        printZ(PolynomsZ[countZ]);
                        countZ++;
                        break;
                    }
                    case 2:{
                        int NUM1,NUM2;
                        printf("Enter NUM1\n");
                        scanf("%d",&NUM1);
                        printf("Enter NUM2\n");
                        scanf("%d",&NUM2);
                        PolynomsC[countC] = compositionC(PolynomsC[NUM1],PolynomsC[NUM2]);
                        printf("Composition result: ");
                        printC(PolynomsC[countC]);
                        countC++;
                        break;
                    }
                }
                scanf("%*c");
                break;
            }
            case 6:{
                printf("Choose type:\n 1.Integer\n 2.Complex\n");
                int choose;
                scanf("%d",&choose);
                switch(choose){
                    case 1: {
                        int NUM1,NUM2;
                        printf("Enter NUM1\n");
                        scanf("%d",&NUM1);
                        printf("Enter scalar\n");
                        scanf("%d",&NUM2);
                        scalarZ(PolynomsZ[NUM1],NUM2);
                        printf("Result: ");
                        printZ(PolynomsZ[NUM1]);
                        break;
                    }
                    case 2:{
                        int NUM1;
                        double complex NUM2;
                        printf("Enter NUM1\n");
                        scanf("%d",&NUM1);
                        printf("Enter scalar\n");
                        double re,im;
                        scanf("%lf %lf", &re, &im);
                        __real__ NUM2 = re;
                        __imag__ NUM2 = im;
                        scalarC(PolynomsC[NUM1],NUM2);
                        break;
                    }
                }
                scanf("%*c");
                break;
            }
            case 7:{
                printf("Choose type:\n 1.Integer\n 2.Complex\n");
                int choose;
                scanf("%d",&choose);
                switch(choose){
                    case 1: {
                        int NUM1,NUM2,result;
                        printf("Enter NUM1\n");
                        scanf("%d",&NUM1);
                        printf("Enter point\n");
                        scanf("%d",&NUM2);
                        result = gornerZ(PolynomsZ[NUM1],NUM2);
                        printf("Value at point: %d",result);
                        break;
                    }
                    case 2:{
                        int NUM1;
                        double complex NUM2,result;
                        printf("Enter NUM1\n");
                        scanf("%d",&NUM1);
                        printf("Enter point\n");
                        double re,im;
                        scanf("%lf %lf", &re, &im);
                        __real__ NUM2 = re;
                        __imag__ NUM2 = im;
                        result = gornerC(PolynomsC[NUM1],NUM2);
                        printf("%lf %lf", creal(result), cimag(result));
                        break;
                    }
                }
                scanf("%*c");
                break;
            }
            case 8:{
                printf("Choose type:\n 1.Integer\n 2.Complex\n");
                int choose;
                scanf("%d",&choose);
                switch(choose){
                    case 1:{
                        for(int i=0; i<countZ; i++){
                            printf("%d)",i);
                            printZ(PolynomsZ[i]);
                        }
                    }
                    case 2:{
                        for(int i=0; i<countC; i++){
                            printf("%d)",i);
                            printC(PolynomsC[i]);
                        }
                    }
                }
                scanf("%*c");
                break;
            }
        }
    }
    for (int i = 0; i< countZ; i++){
        del(PolynomsZ[i]);
    }
    for (int i = 0; i< countC; i++){
        del(PolynomsC[i]);
    }
    free(PolynomsZ);
    free(PolynomsC);
    return 0;
}
#include "tests.h"
void testcompozitionZ(){
    FILE * qwer = fopen("tests/compozitionZ","r");
    if (!qwer) {
        fprintf(stderr, "File compozitionZ don't open \n");
        return;
    }
    int counttest;
    fscanf(qwer,"%d",&counttest);
    for(int n=0; n< counttest;n++){
        int deg1,deg2;
        vector *p1 = create (sizeof(int));
        vector *p2 = create (sizeof(int));
        fscanf(qwer,"%d",&deg1);
        int * q = (int *)calloc(deg1 + 1, sizeof(int));
        for(int i = 0; i < deg1 + 1; i++) {
            fscanf(qwer, "%d", q + i);
        }
        push(p1, q, deg1 + 1);
        fscanf(qwer,"%d",&deg2);
        int * q1 = (int *)calloc(deg2 + 1, sizeof(int));
        for(int i = 0; i < deg2 + 1; i++) {
            fscanf(qwer, "%d", q1 + i);
        }
        push(p2, q1, deg2 + 1);
        vector * comp = compositionZ(p1, p2);
        int deg3;
        fscanf(qwer, "%d", &deg3);
        int * q2 = (int *)calloc(deg3 + 1, sizeof(int));
        for(int i = 0; i < deg3 + 1; i++) {
            fscanf(qwer, "%d", q2 + i);
        }
        int equl = memcmp(comp->head, q2, (deg3  + 1) * sizeof(int));
        if (equl) {
            fprintf(stderr ," EROOR in %d test form compozitionZ.\n", n);
        }
        free(q1);
        free(q);
    }
    fclose(qwer);
}
void testsumZ(){
    FILE * qwer = fopen("tests/sumZ","r");
    if (!qwer) {
        fprintf(stderr, "File sumZ don't open \n");
        return;
    }
    int counttest;
    fscanf(qwer,"%d",&counttest);
    for(int n=0; n< counttest;n++){
        int deg1,deg2;
        vector *p1 = create (sizeof(int));
        vector *p2 = create (sizeof(int));
        fscanf(qwer,"%d",&deg1);
        int * q = (int *)calloc(deg1 + 1, sizeof(int));
        for(int i = 0; i < deg1 + 1; i++) {
            fscanf(qwer, "%d", q + i);
        }
        push(p1, q, deg1 + 1);
        fscanf(qwer,"%d",&deg2);
        int * q1 = (int *)calloc(deg2 + 1, sizeof(int));
        for(int i = 0; i < deg2 + 1; i++) {
            fscanf(qwer, "%d", q1 + i);
        }
        push(p2, q1, deg2 + 1);
        vector * comp = sumZ(p1, p2);
        int deg3;
        fscanf(qwer, "%d", &deg3);
        int * q2 = (int *)calloc(deg3 + 1, sizeof(int));
        for(int i = 0; i < deg3 + 1; i++) {
            fscanf(qwer, "%d", q2 + i);
        }
        int equl = memcmp(comp->head, q2, (deg3 + 1) * sizeof(int));
        if (equl) {
            fprintf(stderr ," EROOR in %d test sumZ.", n);
        }
        free(q1);
        free(q);
    }
    fclose(qwer);
}
void testscalarZ(){
    FILE * qwer = fopen("tests/scalarZ","r");
    if (!qwer) {
        fprintf(stderr, "File scalarZ don't open \n");
        return;
    }
    int counttest;
    fscanf(qwer,"%d",&counttest);
    for(int n=0; n< counttest;n++){
        int deg1,deg2;
        vector *p1 = create (sizeof(int));
        fscanf(qwer,"%d",&deg1);
        int * q = (int *)calloc(deg1  + 1, sizeof(int));
        for(int i = 0; i < deg1 + 1; i++) {
            fscanf(qwer, "%d", q + i);
        }
        push(p1, q, deg1 + 1);
        fscanf(qwer,"%d",&deg2);
        scalarZ(p1,deg2);
        int deg3;
        fscanf(qwer, "%d", &deg3);
        int * q2 = (int *)calloc(deg3 + 1, sizeof(int));
        for(int i = 0; i < deg3 + 1; i++) {
            fscanf(qwer, "%d", q2 + i);
        }
        int equl = memcmp(p1->head, q2, (deg3 + 1) * sizeof(int));
        if (equl) {
            fprintf(stderr ," EROOR in %d test scalarZ.", n);
        }
        free(q);
    }
    fclose(qwer);
}
void testgornerZ(){
    FILE * qwer = fopen("tests/gornerZ","r");
    if (!qwer) {
        fprintf(stderr, "File gornerZ don't open \n");
        return;
    }
    int counttest;
    fscanf(qwer,"%d",&counttest);
    for(int n=0; n< counttest;n++){
        int deg1,deg2;
        vector *p1 = create (sizeof(int));
        fscanf(qwer,"%d",&deg1);
        int * q = (int *)calloc(deg1 + 1, sizeof(int));
        for(int i = 0; i < deg1 + 1; i++) {
            fscanf(qwer, "%d", q + i);
        }
        push(p1, q, deg1 + 1);
        fscanf(qwer,"%d",&deg2);
        int vall = gornerZ(p1, deg2);
        int deg3;
        fscanf(qwer, "%d", &deg3);
        int equl = (deg3 == vall);
        if (!equl) {
            fprintf(stderr ," EROOR in %d test gornerZ.", n);
        }
        free(q);
    }
    fclose(qwer);
}
void testcompozitionC(){
    FILE * qwer = fopen("tests/compozitionC","r");
    if (!qwer) {
        fprintf(stderr, "File compozitionC don't open \n");
        return;
    }
    int counttest;
    fscanf(qwer,"%d",&counttest);
    for(int n=0; n< counttest;n++){
        int deg1,deg2;
        vector *p1 = create (sizeof(double complex));
        vector *p2 = create (sizeof(double complex));
        fscanf(qwer,"%d",&deg1);
        double complex * q = (double complex *)calloc((deg1 + 1), sizeof(double complex));
        for(int i = 0; i < (deg1 + 1); i++) {
            double re = 0;
            double im = 0;
            fscanf(qwer, "%lf %lf", &re, &im);
            __real__ q[i] = re;
            __imag__ q[i] = im;
        }
        push(p1, q, deg1 + 1);
        fscanf(qwer,"%d",&deg2);
        double complex * q1 = (double complex *)calloc((deg2 + 1), sizeof(double complex));
        for(int i = 0; i < (deg2 + 1); i++) {
            double re = 0;
            double im = 0;
            fscanf(qwer, "%lf %lf", &re, &im);
            __real__ q1[i] = re;
            __imag__ q1[i] = im;
        }
        push(p2, q1, deg2 + 1);
        vector * comp = compositionC(p1, p2);
        int deg3;
        fscanf(qwer, "%d", &deg3);
        double complex * q2 = (double complex *)calloc((deg3 + 1), sizeof(double complex));
        for(int i = 0; i < (deg3 + 1); i++) {
            double re = 0;
            double im = 0;
            fscanf(qwer, "%lf %lf", &re, &im);
            __real__ q2[i] = re;
            __imag__ q2[i] = im;
        }
        int equl = memcmp(comp->head, q2, (deg3  + 1) * sizeof(double complex));
        if (equl) {
            fprintf(stderr ," EROOR in %d test form .\n", n);
        }
        free(q1);
        free(q);
    }
    fclose(qwer);
}
void testsumC(){
    FILE * qwer = fopen("tests/sumC","r");
    if (!qwer) {
        fprintf(stderr, "File sumC don't open \n");
        return;
    }
    int counttest;
    fscanf(qwer,"%d",&counttest);
    for(int n=0; n< counttest;n++){
        int deg1,deg2;
        vector *p1 = create (sizeof(double complex));
        vector *p2 = create (sizeof(double complex));
        fscanf(qwer,"%d",&deg1);
        double complex * q = (double complex *)calloc((deg1 + 1), sizeof(double complex));
        for(int i = 0; i < (deg1 + 1); i++) {
            double re = 0;
            double im = 0;
            fscanf(qwer, "%lf %lf", &re, &im);
            __real__ q[i] = re;
            __imag__ q[i] = im;
        }
        push(p1, q, deg1 + 1);
        fscanf(qwer,"%d",&deg2);
        double complex * q1 = (double complex *)calloc((deg2 + 1), sizeof(double complex));
        for(int i = 0; i < (deg2 + 1); i++) {
            double re = 0;
            double im = 0;
            fscanf(qwer, "%lf %lf", &re, &im);
            __real__ q1[i] = re;
            __imag__ q1[i] = im;
        }
        push(p2, q1, deg2 + 1);
        vector * comp = sumC(p1, p2);
        int deg3;
        fscanf(qwer, "%d", &deg3);
        double complex * q2 = (double complex *)calloc((deg3 + 1), sizeof(double complex));
        for(int i = 0; i < (deg3 + 1); i++) {
            double re = 0;
            double im = 0;
            fscanf(qwer, "%lf %lf", &re, &im);
            __real__ q2[i] = re;
            __imag__ q2[i] = im;
        }
        int equl = memcmp(comp->head, q2, (deg3  + 1) * sizeof(double complex));
        if (equl) {
            fprintf(stderr ," EROOR in %d test form sumC.\n", n);
        }
        free(q1);
        free(q);
    }
    fclose(qwer);
}
void testscalarC(){
    FILE * qwer = fopen("tests/scalarC","r");
    if (!qwer) {
        fprintf(stderr, "File scalarC don't open \n");
        return;
    }
    int counttest;
    fscanf(qwer,"%d",&counttest);
    for(int n=0; n< counttest;n++){
        int deg1;
        double complex deg2;
        vector *p1 = create (sizeof(double complex));
        vector *p2 = create (sizeof(double complex));
        fscanf(qwer,"%d",&deg1);
        double complex * q = (double complex *)calloc((deg1 + 1), sizeof(double complex));
        for(int i = 0; i < (deg1 + 1); i++) {
            double re = 0;
            double im = 0;
            fscanf(qwer, "%lf %lf", &re, &im);
            __real__ q[i] = re;
            __imag__ q[i] = im;
        }
        push(p1, q, deg1 + 1);
        double re,im;
        fscanf(qwer, "%lf %lf", &re, &im);
            __real__ deg2 = re;
            __imag__ deg2 = im;
        scalarC(p1, deg2);
        int deg3;
        fscanf(qwer, "%d", &deg3);
        double complex * q2 = (double complex *)calloc((deg3 + 1), sizeof(double complex));
        for(int i = 0; i < (deg3 + 1); i++) {
            double re = 0;
            double im = 0;
            fscanf(qwer, "%lf %lf", &re, &im);
            __real__ q2[i] = re;
            __imag__ q2[i] = im;
        }
        int equl = memcmp(p1->head, q2, (deg3  + 1) * sizeof(double complex));
        if (equl) {
            fprintf(stderr ," EROOR in %d test form scalarC.\n", n);
        }
        free(q);
    }
    fclose(qwer);
}
void testgornerC(){
    FILE * qwer = fopen("tests/gornerC","r");
    if (!qwer) {
        fprintf(stderr, "File gornerC don't open \n");
        return;
    }
    int counttest;
    fscanf(qwer,"%d",&counttest);
    for(int n=0; n< counttest;n++){
        int deg1;
        double complex deg2;
        double re, im;
        vector *p1 = create (sizeof(double complex));
        fscanf(qwer,"%d",&deg1);
        double complex * q = (double complex *)calloc((deg1 + 1), sizeof(double complex));
        for(int i = 0; i < (deg1 + 1); i++) {
            double re = 0;
            double im = 0;
            fscanf(qwer, "%lf %lf", &re, &im);
            __real__ q[i] = re;
            __imag__ q[i] = im;
        }
        push(p1, q, deg1 + 1);
        fscanf(qwer, "%lf %lf", &re, &im);
            __real__ deg2 = re;
            __imag__ deg2 = im;
        double complex vall = gornerC(p1, deg2);
        double complex deg3;
        fscanf(qwer, "%lf %lf", &re, &im);
            __real__ deg2 = re;
            __imag__ deg2 = im;
        int equl = (vall == deg3);
        if (equl) {
            fprintf(stderr ," EROOR in %d test form gornerC.\n", n);
        }
        free(q);
    }
    fclose(qwer);
}
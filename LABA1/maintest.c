#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
int main(){
printf("tests started\n");
testcompozitionZ();
testsumZ();
testscalarZ();
testgornerZ();
testcompozitionC();
testsumC();
testgornerC();
testscalarC();
printf("tests ended\n");
    return 0;
}
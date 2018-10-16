#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char string[] = "10.0";
    double v;

    printf("%s\n", string);
    v = (double) atoi(string);
    printf("%f", v);

}

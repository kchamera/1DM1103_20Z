#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    float v;
    float a;
    
    a = atof(argv[1]);
    v = a*a;
    
    printf("Wartość %.f do kwadratu to %.f.\n", a, v);
    
    return  0;
}

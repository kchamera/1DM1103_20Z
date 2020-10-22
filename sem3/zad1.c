#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    int v;
    int a;
    
    a = atof(argv[1]);
    v = a*a;
    
    printf("Wartość %.d do kwadratu to %.d.\n", a, v);
    
    return  0;
}

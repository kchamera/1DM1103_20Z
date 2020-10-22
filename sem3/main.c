#include <stdio.h>

void tabliczka(int a, int b){
    
#define x 10
#define y 10
    
    int i, j;
    
    for (i=1; i<=a; i++) {
        for (j=1; j<=b; j++) {
            printf("%5d", i*j);
        }
        printf("\n");
    }
}

int main(){
    tabliczka (x,y);
}

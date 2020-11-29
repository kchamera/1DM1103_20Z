#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"
#include "operacje.h"


int main(int argc, char *argv[]) {
    FILE * fin;
    macierz *mac;
    macierz *macb;
        
    fin  = fopen(argv[2], "r");
    mac = wczytaj(fin);
 if ( strcmp( argv[1], "norm") == 0) {
        float i = norm(mac);

    if(argc == 4){
        zapisz2(argv[3], i);
        }

    else{
        printf("Norma macierzy %s = %f", argv[2], i);
        printf("\n");
        }
    } 
    else if ( strcmp( argv[1], "sum") == 0) {
        fin  = fopen(argv[3], "r");
        macb = wczytaj(fin);

        if(mac->r == macb->r && mac->c == macb->c){
            if(argc ==5){
                zapisz(argv[4], sum(mac, macb));
            }
            else{
            wypisz(mac);
            wypisz(macb);
            printf("Suma macierzy %s i %s =\n", argv[2], argv[3]);
            wypisz(sum(mac, macb));
            printf("\n");
            }
        }
        else{
            printf("Macierzy nie mozna dodac.\n");
        }
    } 
    else if ( strcmp( argv[1], "substract") == 0) {
        fin  = fopen(argv[3], "r");
        macb = wczytaj(fin);

        if(mac->r == macb->r && mac->c == macb->c){
            if(argc ==5){
                zapisz(argv[4], substract(mac, macb));
            }
            else{
            wypisz(mac);
            wypisz(macb);
            printf("Roznica macierzy %s i %s =\n", argv[2], argv[3]);
            wypisz(substract(mac, macb));
            printf("\n");
            }
        }
        else{
            printf("Macierzy nie mozna odjac.\n");
        }
    } 
    else if ( strcmp( argv[1], "prod") == 0) {
        fin  = fopen(argv[3], "r");
        macb = wczytaj(fin);

        if(mac->c == macb->r){
            if(argc ==5){
                zapisz(argv[4], prod(mac, macb));
            }
            else{
            wypisz(mac);
            wypisz(macb);
            printf("Iloczyn macierzy %s i %s =\n", argv[2], argv[3]);
            wypisz(prod(mac, macb));
            printf("\n");
            }
        }
        else{
            printf("Macierzy nie mozna pomnozyc.\n");
        }
    } 
    else if ( strcmp( argv[1], "multiply") == 0) {

            if(argc ==5){
                zapisz(argv[4], multiply(mac, atof(argv[3])));
            }
            else{
            wypisz(mac);
            printf("Iloczyn macierzy %s przez skalar %s =\n", argv[2], argv[3]);
            wypisz(multiply(mac, atof(argv[3])));
            printf("\n");
            }
    } 
    else {
        printf("Nierozpoznany argument %s. Oczekiwałem: norm lub sum lub substract lub multiply lub prod.\n", argv[1]);
    }    
    zwolnij(mac);
    zwolnij(macb);
    return 0;
}

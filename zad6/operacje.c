#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"

float norm(macierz *m)
{
    float s = 0;

    for (int i = 0; i < m->r; i++) {
        for (int j = 0; j < m->c; j++) {
            s += m->tab[i][j] * m->tab[i][j];
        }
    }
    return sqrt(s);
}

macierz *sum(macierz *mac, macierz *macb)
{
    macierz *suma;
    suma = (macierz*) malloc(sizeof(macierz));
    suma->r=mac->r;
    suma->c=mac->c;

suma->tab = (float**) malloc(sizeof(float*) * suma->r);
    for(int i = 0; i < suma->r; i++){
        suma->tab[i] = (float*) malloc(sizeof(float) * suma->c);
        for(int j = 0; j < suma->c; j++)
            suma->tab[i][j] = mac->tab[i][j] + macb->tab[i][j];}
    
    return suma;
}

macierz *substract(macierz *mac, macierz *macb)
{
    macierz *suma;
    suma = (macierz*) malloc(sizeof(macierz));
    suma->r=mac->r;
    suma->c=mac->c;

suma->tab = (float**) malloc(sizeof(float*) * suma->r);
    for(int i = 0; i < suma->r; i++){
        suma->tab[i] = (float*) malloc(sizeof(float) * suma->c);
        for(int j = 0; j < suma->c; j++)
            suma->tab[i][j] = mac->tab[i][j] - macb->tab[i][j];}
    
    return suma;
}

macierz *multiply(macierz *mac, float x)
{
    macierz *suma;
    suma = (macierz*) malloc(sizeof(macierz));
    suma->r=mac->r;
    suma->c=mac->c;

suma->tab = (float**) malloc(sizeof(float*) * suma->r);
    for(int i = 0; i < suma->r; i++){
        suma->tab[i] = (float*) malloc(sizeof(float) * suma->c);
        for(int j = 0; j < suma->c; j++)
            suma->tab[i][j] = (mac->tab[i][j] * x);}
    
    return suma;
}

macierz *prod(macierz *mac, macierz *macb)
{   
    macierz *wynik;
    wynik = (macierz*) malloc(sizeof(macierz));
        wynik->r = mac->r;
        wynik->c = macb->c;

        wynik->tab = (float**) malloc(sizeof(float*) * wynik->r);
        for(int i=0; i<mac->r; i++){
        wynik->tab[i] = (float*) malloc(sizeof(float) * wynik->c);
            for(int j=0; j<macb->c; j++)
                for(int p=0; p<mac->c; p++)
                {
                    wynik->tab[i][j] += mac->tab[i][p] * macb->tab[p][j];
                }
        }
        return wynik; 
}

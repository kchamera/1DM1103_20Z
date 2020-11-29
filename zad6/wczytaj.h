#ifndef _WCZYTAJ_H
#define _WCZYTAJ_H

typedef struct _macierz {
    int r;
    int c;
    float **tab;
} macierz;

macierz *wczytaj(FILE * fin);
macierz *wypisz(macierz *m);
void zapisz(char nazwa[], macierz *m);
void zapisz2(char nazwa[], float i);
void zwolnij(macierz *m);

#endif
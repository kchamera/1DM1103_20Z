#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"

macierz *wczytaj(FILE *fin) {
    macierz *ms;
    int i,j;
    ms = (macierz*) malloc(sizeof(macierz));
    fscanf(fin, "%d", &ms->r);
    fscanf(fin, "%d", &ms->c);

  ms->tab = (float**) malloc(sizeof(float*) * ms->r);
    for (i=0;i<ms->r;i++) {
        ms->tab[i] = (float*) malloc(sizeof(float) * ms->c);}
        for (i=0;i<ms->r;i++){
            for (j=0;j< ms->c; j++)
            fscanf(fin, "%f", &ms->tab[i][j]);
    }
    fclose(fin);
    return ms;
}
       
macierz *wypisz(macierz *m) {
    printf("[");
    for (int i = 0; i < m->r; i++) {
        for (int j = 0; j < m->c; j++) {
            printf("%5.1f ", m->tab[i][j]);
        }
        if (i < (m->r-1))
            printf("\n  ");
    }
    printf("]\n");
    return m;
}

void zapisz(char nazwa[], macierz *m) {
    
    FILE * fout = fopen(nazwa, "w");
    fprintf(fout, "%d\n%d\n", m->r, m->c);

    for (int i = 0; i < m->r; i++) {
        for (int j = 0; j < m->c; j++) {
            fprintf(fout, "%.f\n", m->tab[i][j]);
        }
    }

    fclose(fout);
}

void zapisz2(char nazwa[], float i) {
  
    FILE * fout = fopen(nazwa, "w");
    fprintf(fout, "%f\n", i);
    fclose(fout);
}

void zwolnij(macierz *m){
    for (int i = 0; i < m->r; i++) 
    free( m->tab[i] );
    free(m->tab);
    free(m);
}
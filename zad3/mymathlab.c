#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct macierz {
    int r;
    int c;
    float tab[200][200];
};

void wczytaj(FILE * fin, struct macierz *m) {
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);

    for (int i = 0; i < m->r; i++) {
        for (int j=0; j < m->c; j++) {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }
}

void wypisz(struct macierz m) {
    printf("[");
    for (int i = 0; i < m.r; i++) {
        for (int j = 0; j < m.c; j++) {
            printf("%5.1f ", m.tab[i][j]);
        }
        if (i < (m.r-1))
            printf("\n  ");
    }
    printf("]\n");
}

float norm(struct macierz m)
{
    float s = 0;

    for (int i = 0; i < m.r; i++) {
        for (int j = 0; j < m.c; j++) {
            s += m.tab[i][j] * m.tab[i][j];
        }
    }
    return sqrt(s);
}

struct macierz sum(struct macierz mac, struct macierz macb)
{
    struct macierz suma;
    suma.r=mac.r;
    suma.c=mac.c;

    for(int i = 0; i < mac.r; i++){
        for(int j = 0; j < mac.c; j++)
            suma.tab[i][j] = mac.tab[i][j] + macb.tab[i][j];
    }
    return suma;
}

struct macierz substract(struct macierz mac, struct macierz macb)
{
    struct macierz suma;
    suma.r=mac.r;
    suma.c=mac.c;

    for(int i = 0; i < mac.r; i++){
        for(int j = 0; j < mac.c; j++)
            suma.tab[i][j] = mac.tab[i][j] - macb.tab[i][j];
    }
    return suma;
}

struct macierz multiply(struct macierz mac, float x)
{
    struct macierz suma;
    suma.r=mac.r;
    suma.c=mac.c;

    for(int i = 0; i < mac.r; i++){
        for(int j = 0; j < mac.c; j++)
            suma.tab[i][j] = mac.tab[i][j] * x;
    }
    return suma;
}

struct macierz prod(struct macierz mac, struct macierz macb)
{   
    struct macierz wynik;
        wynik.r = mac.r;
        wynik.c = macb.c;
        for(int i=0; i<mac.r; i++)
            for(int j=0; j<macb.c; j++)
                for(int p=0; p<mac.c; p++)
                {
                    wynik.tab[i][j] += mac.tab[i][p] * macb.tab[p][j];
                }
        return wynik; 
}

void zapisz(char nazwa[], struct macierz m) {
    
    FILE * fout = fopen(nazwa, "w");
    fprintf(fout, "%d\n%d\n", m.r, m.c);

    for (int i = 0; i < m.r; i++) {
        for (int j = 0; j < m.c; j++) {
            fprintf(fout, "%.f\n", m.tab[i][j]);
        }
    }

    fclose(fout);
}

void zapisz2(char nazwa[], float i) {
  
    FILE * fout = fopen(nazwa, "w");
    fprintf(fout, "%f\n", i);
    fclose(fout);
}

int main(int argc, char *argv[]) {
    struct macierz mac;
    struct macierz macb;
       struct macierz wynik;
       struct macierz wynik2;
       struct macierz wynik3;
       struct macierz wynik4;
    
        FILE * fin;
        fin  = fopen(argv[2], "r");
        wczytaj(fin, &mac);

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
        wczytaj(fin, &macb);

        if(mac.r == macb.r && mac.c == macb.c){
       
        wynik = sum(mac, macb);

        if(argc == 5){
            zapisz(argv[4], wynik);
            }
        else{
            wypisz(mac);
            wypisz(macb);
            printf("Suma macierzy %s i %s = ", argv[2], argv[3]);
            wypisz(wynik);
            printf("\n");
            }

        }
        else{
            printf("Macierzy nie mozna dodac.\n");
        }
    } 
    else if ( strcmp( argv[1], "substract") == 0) {
        fin  = fopen(argv[3], "r");
        wczytaj(fin, &macb);

        if(mac.r == macb.r && mac.c == macb.c){
       
        wynik2 = substract(mac, macb);

        if(argc == 5){
            zapisz(argv[4], wynik2);
            }
        else{
            wypisz(mac);
            wypisz(macb);
            printf("Roznica macierzy %s i %s = ", argv[2], argv[3]);
            wypisz(wynik2);
            printf("\n");
            }

        }
        else{
            printf("Macierzy nie mozna odjac.\n");
        }
    } 
    else if ( strcmp( argv[1], "multiply") == 0) {
        wynik3 = multiply(mac, atof(argv[3]));

        if(argc == 5){
        zapisz(argv[4], wynik3);
        }
        else{
        wypisz(mac);
        printf("Iloczyn macierzy %s przez skalar %s = ", argv[2], argv[3]);
        wypisz(wynik3);
        printf("\n");
        }
    }
    else if ( strcmp( argv[1], "prod") == 0) {
        fin  = fopen(argv[3], "r");
        wczytaj(fin, &macb);
        wynik4 = prod(mac, macb);

        if (mac.c == macb.r){
        if (argc == 5){
        zapisz(argv[4], wynik4);
            }
        else{
        wypisz(mac);
        wypisz(macb);
        printf("Iloczyn macierzy %s i %s = ", argv[2], argv[3]);
        wypisz(wynik4);
        printf("\n");
            }
        }
        else{
            printf("Macierzy nie mozna wymnozyc.\n");
        }
    }
    else {
        printf("Nierozpoznany argument %s. Oczekiwałem: norm lub sum lub substract lub multiply lub prod.\n", argv[1]);
    }    
    return 0;
}

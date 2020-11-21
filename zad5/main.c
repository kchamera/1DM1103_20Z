#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenci.h"
#include "dziekanat.h"

int main(int argc, char ** argv) {
    student dane[100];
    int ile;

    ile = wczytaj(dane, argv[2]);
    wypisz(dane, ile);

    if (strcmp( argv[1], "najlepszy_student") == 0){
    najlepszy_student(dane,ile);
    }
    else if (strcmp( argv[1], "najtrudniejszy_przedmiot") == 0){
    najtrudniejszy_przedmiot(dane,ile);
    }
    else if (strcmp( argv[1], "najlatwiejszy_przedmiot") == 0){
    najlatwiejszy_przedmiot(dane,ile);
    }
    else {
    printf("Nierozpoznany argument %s.\n", argv[1]);
    }
    return 0;
}
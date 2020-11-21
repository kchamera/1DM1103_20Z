#ifndef _DZIEKANAT_H
#define _DZIEKANAT_H

#include "studenci.h"

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

int znajdz_przedmiot(char kod_przed[100][10], student dane[100], int n);
void najtrudniejszy_przedmiot(student dane[100], int ile_rekordow);
void najlatwiejszy_przedmiot(student dane[100], int ile_rekordow);
void najlepszy_student(student dane[100], int ile_rekordow);

#endif
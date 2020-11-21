#ifndef _STUDENCI_H
#define _STUDENCI_H

#include "dziekanat.h"

int wczytaj(student dane[100], char *fnazwa);
 
void wypisz(student dane[100], int n);
 
int znajdz(char *szukany_nr, char kod_przedmiotu[100][10], int n);
 
int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);

#endif
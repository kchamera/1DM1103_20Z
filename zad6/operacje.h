#ifndef _OPERACJE_H
#define _OPERACJE_H

float norm(macierz *m);
macierz *sum(macierz *mac, macierz *macb);
macierz *substract(macierz *mac, macierz *macb);
macierz *multiply(macierz *mac, float x);
macierz *prod(macierz *mac, macierz *macb);

#endif
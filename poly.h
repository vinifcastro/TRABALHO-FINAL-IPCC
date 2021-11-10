#ifndef POLY_H
#define POLY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_SIZE 5

typedef struct {
	char code[ID_SIZE];
	int p;
	double* coef;
} Poly;

typedef struct {
	double x;
    int pot;
} temp;

#endif

void escrevepoly(FILE * a, Poly b, int x);

temp * alocacao(int size);

int maiorpot(temp * a, int size);
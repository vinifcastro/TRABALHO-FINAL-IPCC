#include "poly.h"

temp * alocacao(int size){
    temp * a = NULL;
    a = (temp *) malloc(size*sizeof(temp));
    return a;
}

int maiorpot(temp * a, int size){
    int i, maiorpot;
    for(i=0;i<size;i++){
        if (i==0) maiorpot = a[i].pot;
        else{
            if (a[i].pot > maiorpot) maiorpot = a[i].pot;
        }
    }
    return maiorpot;
}

void escrevepoly(FILE * a, Poly b, int x){
    x++;
    fwrite(&b.code, sizeof(b.code), 1, a);
    fwrite(&b.p, sizeof(int), 1, a);
    fwrite(b.coef, sizeof(double), x, a);
}
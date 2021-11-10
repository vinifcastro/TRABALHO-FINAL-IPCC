#include "poly.h"

int main(int argc, char **argv){
    FILE * arq = NULL;
    temp * a = NULL;
    Poly polinomio;
    double x;
    int i, mais=1;
    if (argc!=3) {
        printf("Execucao errada! Utilize:\n   ./pbuild <poly_string> <file_name>\n");
        return 0;
    }
    for(i=1;i<strlen(argv[1]); i++){
        if (argv[1][i]=='+' || argv[1][i]=='-') mais++;
    } 
    a = alocacao(mais);
    arq = fopen(argv[2], "w+");
    if (!arq) exit(0);
    fprintf(arq,argv[1]);
    fseek(arq,0,SEEK_SET);
    for (i=0;i<mais;i++){
        fscanf(arq, "%lfx^%d", &a[i].x, &a[i].pot);
    }
    fclose(arq);
    strcpy(polinomio.code,"poly\0");
    polinomio.p = maiorpot(a, mais);
    polinomio.coef = NULL;
    polinomio.coef = (double *) calloc(polinomio.p+1, sizeof(double));
    for (i=0;i<mais;i++){
        polinomio.coef[(a[i].pot)] = a[i].x;
    }
    arq = fopen(argv[2], "wb");
    escrevepoly(arq, polinomio, polinomio.p);
    fclose(arq);
    free(polinomio.coef);
    free(a);
    return 0;
}
#include "poly.h"

int main(int argc, char ** argv) {
    Poly z;
    int i, k;
    int cont = 0;
    FILE * arq = NULL;
    if (argc!=2) printf("Execucao errada! Utilize:\n   ./pview <file_name>\n");
    arq = fopen(argv[1], "rb");
    if (!arq) exit(0);
    fseek(arq,0,SEEK_SET);
    fread(z.code, sizeof(char), ID_SIZE, arq);
    fread(&z.p, sizeof(z.p), 1, arq);
    z.coef = NULL;
    z.coef = (double *) malloc((z.p+1)*sizeof(double));
    fread(z.coef, sizeof(double), (z.p+1), arq);
    fclose(arq);
    k=0;
    for (i=0;i<=z.p;i++){
        if (z.coef[i] == 0) cont++;
        if (i==0 && z.coef[i]!=0){ 
            if (z.coef[i]>0) printf("%.2lf ", z.coef[i]);
            else printf("- %.2lf ", z.coef[i]*-1);
        }
        else if(z.coef[i] != 0 && z.coef[i] > 0) {
            if(k==0){
                if (z.coef[i] == 1 ) printf("x^%d ", i);
                else printf("%.2lfx^%d ", z.coef[i], i);
            }
            else{
                if (z.coef[i] == 1 ) printf("+ x^%d ", i);
                else printf("+ %.2lfx^%d ", z.coef[i], i);
            }
        }
        else if (z.coef[i] != 0 && z.coef[i] < 0) {
            if(k==0){
                if (z.coef[i] == -1 ) printf("- x^%d ", i);
                else printf("- %.2lfx^%d ", (z.coef[i]*-1), i);
            }
            else{
                if (z.coef[i] == -1 ) printf("- x^%d ", i);
                else printf("- %.2lfx^%d ", (z.coef[i]*-1), i);
            }
        }
        if (z.coef[i]!=0) k=1;
    }
    if (cont == (z.p+1)) printf("Todos os valores de x, independentemente do grau, estao multiplicando 0, portanto o polinomio e nulo!");
    printf("\n");
    free(z.coef);
    return 0;
}
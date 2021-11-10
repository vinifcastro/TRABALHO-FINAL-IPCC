#include "poly.h"

int main(int argc, char **argv){
    FILE * arq = NULL;
    Poly z, y, x;
    int i;
    if (argc!=4){
        printf("Execucao errada! Utilize:\n   ./psum <file_name_1> <file_name_2> <file_name_out>\n");
        return 0;
    }
    arq = fopen(argv[1], "rb");
    if (!arq) exit(0);
    fseek(arq,0,SEEK_SET);
    fread(z.code, sizeof(char), ID_SIZE, arq);
    fread(&z.p, sizeof(z.p), 1, arq);
    z.coef = NULL;
    z.coef = (double *) malloc((z.p+1)*sizeof(double));
    fread(z.coef, sizeof(double), (z.p+1), arq);
    fclose(arq);
    arq = fopen(argv[2], "rb");
    if (!arq) exit(0);
    fseek(arq,0,SEEK_SET);
    fread(y.code, sizeof(char), ID_SIZE, arq);
    fread(&y.p, sizeof(y.p), 1, arq);
    y.coef = NULL;
    y.coef = (double *) malloc((y.p+1)*sizeof(double));
    fread(y.coef, sizeof(double), (y.p+1), arq);
    fclose(arq);
    strcpy(x.code, "poly\0");
    if (z.p>y.p) x.p = z.p;
    else x.p = y.p;
    x.coef == NULL;
    x.coef = (double *) calloc((x.p+1),sizeof(double));
    for (i=0;i<=z.p;i++){
        x.coef[i] = z.coef[i];
    }
    for (i=0;i<=y.p;i++) x.coef[i] += y.coef[i];
    arq = fopen(argv[3], "wb");
    escrevepoly(arq, x, x.p);
    fclose(arq);
    free(x.coef);
    free(y.coef);
    free(z.coef);
    return 0;
}
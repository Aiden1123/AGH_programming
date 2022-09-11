//Uklad rownan liniowych: A*x = b
//det A != 0

//A = LU
//PA = LU
//P - macierz permutacji
    //sklada sie tylko z 0 i 1
    //w kazdym wierszu i kolumnie moze byc tylko jedno 0

//przyjmujemy ze na przekatnej macierzy L znajduja sie 1

#include <stdio.h>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

int main() {

    FILE *fp;
    const int n = 4;
    double val;
    gsl_matrix *A = gsl_matrix_calloc(n,n);

    if((fp = fopen("a.txt","rt"))==NULL) {
        printf("did not open file\n");
        return 1;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            fscanf(fp,"%lf ",&val);
            gsl_matrix_set(A,i,j,val);
        }
    }

    printf("\nmacierz A \n\n");

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%.2f ",gsl_matrix_get(A,i,j));
        }
        printf("\n");
    }

    fclose(fp);

}
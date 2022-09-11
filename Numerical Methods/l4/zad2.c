  //Rozklad QR
    /*
        A = QR
        Q - macierz ortogonalna
        R - trojkotna gorna

        macierz odwrotna do macierzy ortogonalnej to jej transpozycja
        nie trzeba odwracac wystarczy Q[j][i]

        Wynik przechowywany w A
    */

#include <stdio.h>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

int main() {

    int n= 5;
    double val;
    FILE *fp;
    gsl_matrix *A = gsl_matrix_calloc(n,n);
 //   gsl_permutation *p = gsl_permutation_calloc(n);
    gsl_vector *b = gsl_vector_calloc(n);


    if((fp = fopen("matrix.txt","rt"))==NULL) {
        printf("did not open file\n");
        return 1;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            fscanf(fp,"%lf ",&val);
            gsl_matrix_set(A,i,j,val);
        }
        fscanf(fp,"%lf ",&val);
        gsl_vector_set(b,i,val);
    }

    gsl_vector *tau = gsl_vector_calloc(n);
    gsl_vector *x = gsl_vector_calloc(n);

    gsl_linalg_QR_decomp(A,tau);    //QR zostana zapisane do A i tau
    gsl_linalg_QR_solve(A,tau,b,x);

    for(int i=0;i<n;i++) {
        printf("%.2lf ",gsl_vector_get(x,i));
    }
    printf("\n");

  
    return 0;
}
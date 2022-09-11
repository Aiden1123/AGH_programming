#include <stdio.h>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

int main() {

    FILE *fp;
    const int n = 4;
    double val;
    gsl_matrix *A = gsl_matrix_calloc(n,n);
    gsl_permutation *p = gsl_permutation_calloc(n);

    if((fp = fopen("matrix.txt","rt"))==NULL) {
        printf("did not open file\n");
        return 1;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            fscanf(fp,"%lf ",&val);
            gsl_matrix_set(A,i,j,val);
        }
    }

    fclose(fp);

    printf("\nmacierz A \n\n");

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%.2f ",gsl_matrix_get(A,i,j));
        }
        printf("\n");
    }

    int s;

    gsl_linalg_LU_decomp(A,p,&s);

    printf("\nrozklad LU \n\n");

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%.2f ",gsl_matrix_get(A,i,j));
        }
        printf("\n");
    }

    gsl_matrix *LU = gsl_matrix_calloc(n,n);
    double lik;     //lik = A[i][k] gdy i>k , gdy i==k => lik=1, gdy i<k => lik=0
    double ukj;     //ukj = A[k][j] gdy j>=k, 0 dla j<k

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            double sum = 0;
            for(int k=0;k<n;k++) {
                //sum += L[i][k] + U[k][j];
                if (i>k) {
                    lik = gsl_matrix_get(A,i,k);
                }
                else {
                    lik = (i==k);
                }

                if (j>=k) {
                    ukj = gsl_matrix_get(A,k,j);
                }
                else {
                    ukj = 0;
                }

                sum += lik * ukj;

            }
            //LU[i][j] = sum
            gsl_matrix_set(LU,i,j,sum);
        }
    }
    
   printf("\nwynik mnozenia L*U \n\n");

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%.2f ",gsl_matrix_get(LU,i,j));
        }
        printf("\n");
    }



}
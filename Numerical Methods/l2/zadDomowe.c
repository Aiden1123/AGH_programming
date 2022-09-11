#include <stdio.h>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

int main() {

    FILE *fp;
    const int n = 5;
    double b[n];
    double val;
    gsl_matrix *A = gsl_matrix_calloc(n,n);
    gsl_permutation *p = gsl_permutation_calloc(n);

    if((fp = fopen("m.txt","rt"))==NULL) {
        printf("did not open file\n");
        return 1;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            fscanf(fp,"%lf ",&val);
            gsl_matrix_set(A,i,j,val);
        }
        fscanf(fp,"%lf ",&val);
        b[i] = val;
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

    printf("\np \n\n");

    for(int i=0;i<n;i++) {
        printf("%ld ",gsl_permutation_get(p,i));
    }

    printf("\n");
    /*
    int q[n];

    //ik = q[k]

    //p[q[k]] == k
    //q[p[k]] == k

    for(int k=0; k < n; k++) {
        q[gsl_permutation_get(p,k)] = k;
    }

    printf("\nA' poprzestawiane poprawnie \n\n");
    for(int i=0;i<n;i++) {
        //wypisac ten wiersz z A'
                for(int j=0;j<n;j++) {
            printf("%.2f ",gsl_matrix_get(A,q[i],j));
        }
        printf("\n");
    }

    gsl_matrix *copy_A = gsl_matrix_calloc(n,n);

    for(int i=0;i<n;i++) {
        //wypisac ten wiersz z A'
        for(int j=0;j<n;j++) {
            gsl_matrix_set(copy_A,q[i],j,gsl_matrix_get(A,q[i],j));
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
                    lik = gsl_matrix_get(copy_A,i,k);
                }
                else {
                    lik = (i==k);
                }

                if (j>=k) {
                    ukj = gsl_matrix_get(copy_A,k,j);
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
            printf("%.2f ",gsl_matrix_get(LU,q[i],j));
        }
        printf("\n");
    }
    */
    gsl_vector *Pb = gsl_vector_calloc(n);

    for(int i=0;i<n;i++) {
        gsl_vector_set(Pb,gsl_permutation_get(p,i),b[i]);
    }

    printf("\nPb \n\n");

    for(int i=0;i<n;i++) {
        printf("%.2f ",gsl_vector_get(Pb,i));
    }

    printf("\n");

    double y[n];
    double sum;
    double x[n];

    for (int i=0;i<n;i++) {
        sum = 0;
        for(int j=0;j<i;j++) {
            sum+= gsl_matrix_get(A,i,j) * y[j];
        }
        y[i] = (gsl_vector_get(Pb,i) - sum);
    }

    for (int i=n-1;i>=0;i--) {
        sum = 0;
        for(int j=i+1;j<n;j++) {
            sum+= gsl_matrix_get(A,i,j) * x[j];
        }
        x[i] = (y[i]- sum)/gsl_matrix_get(A,i,i);
    }

    printf("\ny: \n\n");

    for(int i=0;i<n;i++) {
        printf("%.2f ",y[i]);
    }

    printf("\n");

    printf("\nx: \n\n");

    for(int i=0;i<n;i++) {
        printf("%.2f ",x[i]);
    }

    printf("\n");

}
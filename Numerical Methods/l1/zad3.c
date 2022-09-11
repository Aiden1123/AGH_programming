//gcc <name>.c -lgsl -lgslcblas -lm (-o <nazwa pliku wykonywalnego>)

#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

int main() {

    int m = 4;
    int n = 4;
    int i;
    int j;

    gsl_matrix *A = gsl_matrix_calloc(n,m);
    gsl_vector *b = gsl_vector_calloc(n);

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            gsl_matrix_set(A,i,j, i<j ? 0 : 1.0/(1+i+j));
        }
        gsl_vector_set(b,i,2*i);
    }

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            printf("%f ",gsl_matrix_get(A,i,j));
        }
        printf("\n");
    }    

    printf("\n");

    for(i=0;i<n;i++) {
        printf("%f ",gsl_vector_get(b,i));
    }

    printf("\n");


    double x[n];
    double sum;

    for (i=0;i<n;i++) {
        sum = 0;
        for(j=0;j<i;j++) {
            sum+= gsl_matrix_get(A,i,j) * x[j];
        }
        x[i] = (gsl_vector_get(b,i) - sum)/gsl_matrix_get(A,i,i);
    }

    printf("\n");

    for(i=0;i<n;i++) {
        printf("%f ",x[i]);
    }

    printf("\n");

    return 0;
}

//n - liczba wierszy
//m - liczba kolumn

//rozklad LU aka LU decomposition

// Ax = b
// A = LU
// LUx = b

// L - macierz trojkatna dolna
// U - macierz trojkatna gorna


// Ly = b
// Ux = y

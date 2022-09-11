#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include <math.h>

int main() {

    const int n = 3;
    const int m = 1;

    double x[] = {0,1,2,3};
    double y[] = {0,1,2,3};

    

    gsl_matrix *G = gsl_matrix_calloc(m,m);
    gsl_vector *ro = gsl_vector_calloc(m);
    gsl_vector *a = gsl_vector_calloc(m);

    double s;
    for (int i;i<m;i++) {
        for(int j;j<m;j++) {
            s = 0;
            for(int k=0;k<=n;k++) {
                s += pow(x[k],i+j);
            }    
            gsl_matrix_set(G,i,j,s);
        }
    }

    for(int i=0;i<m;i++) {
        s = 0;
        for(int k=0;k<=n;k++) {
            s += y[k] * pow(x[k],i);
        }
        gsl_vector_set(ro,i,s);
    }

    int signum;
    gsl_permutation *p = gsl_permutation_calloc(m);
    gsl_linalg_LU_decomp(G, p, &signum);
    gsl_linalg_LU_solve(G,p,ro,a);

    double r_squared = 0;

    for(int j=0;j<=n;j++) {
        s = 0;
        for(int i=0;i<=m;i++) {
            s += gsl_vector_get(a,i)*pow(x[j],i);
        }
        r_squared += (y[j] - s)*(y[j] - s);
    }

    r_squared/= n+1;

    printf("r_squared = %.2f\n",r_squared);

    for(int i=0;i<m;i++){
        printf("%.2f\n", gsl_vector_get(a,i));
    }
}
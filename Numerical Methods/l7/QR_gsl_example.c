#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#define n 5
int main (void) {
    
    double A[n*n];
    double A_copy[n*n];
    int i, j;
    
    for(i=0; i < n; i++)
        for(j=0; j < n; j++) 
            A[n*i + j] = 1 + (i+j) + 1.0*cos(i*j)/(1.5+sin(i+j));
    /*
    A[0] = 1;
    A[1] = 2;
    A[2] = 2;
    A[3] = -1;
    */
    for(i=0;i<n*n;i++) {
        A_copy[i] = A[i];
    }

    gsl_vector *wart_wlasne = gsl_vector_alloc(n);
    gsl_matrix *wekt_wlasne = gsl_matrix_alloc(n, n);
    
    gsl_matrix_view A_mv = gsl_matrix_view_array(A, n, n);
    
    gsl_eigen_symmv_workspace *wsp = gsl_eigen_symmv_alloc(n);// Tutaj jest dokonywany rozkład QR
    
    gsl_eigen_symmv (&A_mv.matrix, wart_wlasne, wekt_wlasne, wsp);
    
    gsl_eigen_symmv_free(wsp);
    
    gsl_eigen_symmv_sort(wart_wlasne, wekt_wlasne, GSL_EIGEN_SORT_ABS_ASC);
    
    double maxVal = 0;

    for(i = 0; i < n; i++) {
        
        double wart_i = gsl_vector_get (wart_wlasne, i);

        if (fabs(wart_i) > maxVal) {
            maxVal = wart_i;
        }
        
        gsl_vector_view wekt_i = gsl_matrix_column(wekt_wlasne, i);
        
        /*
        printf("wartość własna = %lf\n", wart_i);
        printf("wektor własny = \n");
        
        gsl_vector_fprintf(stdout, &wekt_i.vector, "%lf");
        */

        printf("%.2f -> [",wart_i);

        for(j=0;j<n;j++) {
            printf("%.2f", gsl_matrix_get(wekt_wlasne,j,i));
            if (j!=n-1) printf(",");
        }

        printf("]\n");


        double left[n];
        double right[n];

        for(j=0;j<n;j++) {
            left[j] = 0;
            for(int k=0;k<n;k++) {
                left[j] += gsl_matrix_get(wekt_wlasne,k,i) * A_copy[j*n + k];
            }
            right[j] = gsl_matrix_get(wekt_wlasne,j,i) * wart_i;


            if (fabs(left[j]-right[j]) < 1e-3) {
                printf("wartosc poprawna\n");
            }
            else {
                printf("wartosc niepoprawna\n");
                printf("lewa strona: %f, prawa strona: %f\n",left[j],right[j]);
            }

        }
    }

    double v[n];

    for(i=0;i<n;i++) {
        
    }

    for(int k=0;k<100;k++) {

    }

        
    gsl_vector_free(wart_wlasne);
    gsl_matrix_free(wekt_wlasne);
        
    return 0;
}
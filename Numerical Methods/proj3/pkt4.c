#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

double abs_double(double x) {
    return x>0 ? x : -x;
}

void solve_jacobi(unsigned size, double (*A)[size], double *b, double *xk, double *xkp1, unsigned iterations);

int main() {
    double A[SIZE][SIZE] = { {      4, 2.0/7.0,       1, 1.0/3.0, 1.0/6.0, 1.0/5.0},
                             {1.0/3.0,      -5, 1.0/5.0, 3.0/2.0, 2.0/7.0, 1.0/8.0},
                             {1.0/9.0, 1.0/6.0,      -3,      -1, 1.0/6.0, 2.0/7.0},
                             {1.0/5.0, 1.0/2.0,      -1,       8,       2, 1.0/3.0},
                             {1.0/8.0, 1.0/3.0,3.0/10.0, 1.0/8.0,       3, 1.0/4.0},
                             {2.0/7.0,       2, 1.0/6.0, 1.0/5.0,      -1,       6} };

    double Ainverse[SIZE][SIZE];
    double e[SIZE] = {0};
    double xk[SIZE] = {0};
    double xkp1[SIZE];

    for(int i=0;i<SIZE;i++) {
        e[i] = 1;
        if (i-1>=0) {
            e[i-1] = 0;
        }

        solve_jacobi(SIZE,A,e,xk,xkp1,100);

        for(int j=0;j<SIZE;j++) {
            Ainverse[j][i] = xkp1[j];
        }
    }

    //save to file
    FILE *f;

    if((f = fopen("res.txt","wt"))==NULL) {
        printf("did not open file\n");
        return 1;
    }


    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            fprintf(f,"%lf ",Ainverse[i][j]);
        }
        fprintf(f,"\n");
    }
    fclose(f);

    //mult

    double mult[SIZE][SIZE];

    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            mult[i][j] = 0;
            for(int k=0;k<SIZE;k++) {
                mult[i][j] += Ainverse[i][k] * A[k][j];    
            }
        }
    }

    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            printf("%.2lf ",mult[i][j]);
        }
        printf("\n");
    }

    return 0;
}


void solve_jacobi(unsigned size, double (*A)[size], double *b, double *xk, double *xkp1, unsigned iterations) {
    for(int k=0;k<iterations;k++) {

        for(int i=0;i<size;i++) {
            xkp1[i] = b[i]/A[i][i];
            for(int j=0;j<size;j++) {
                if (i==j)
                    continue;
                xkp1[i] -= (A[i][j]/A[i][i])*xk[j];
            }
        }

        if (!(k%10)) {
            printf("iteracja %3d:  ",k);
            for(int l=0;l<size;l++) {
                printf("%.4lf  ", xkp1[l]);
            }
            printf("\n");
        }

        for(int l=0;l<size;l++)
            xk[l] = xkp1[l];
    }
}
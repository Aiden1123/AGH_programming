#include <stdio.h>
#define N 5


int main() {
    FILE *fp;
    double d[N];           
    double x[N];                    
    double c[N-1];
    double a[N];
    double b[N];

    if((fp = fopen("dane.txt","rt"))==NULL) {
        printf("did not open file\n");
        return 1;
    }

    for(int i=0;i<N-1;i++) {
        fscanf(fp,"%lf",c+i);
    }

    for(int i=0;i<N;i++) {
        fscanf(fp,"%lf",d+i);
    }
    
    for(int i=1;i<N;i++) {
        fscanf(fp,"%lf",a+i);
    }
    
    for(int i=0;i<N;i++) {
        fscanf(fp,"%lf",b+i);
    }
    fclose(fp);    

    for(int i=1;i<N;i++) {
        d[i] = d[i] - c[i-1] * (a[i]/d[i-1]);
        b[i] = b[i] - b[i-1] * (a[i]/d[i-1]);       
    }

    x[N-1] = b[N-1]/d[N-1];

    for (int i=N-2;i>=0;i--) {
        x[i] = (b[i] - c[i] * x[i+1])/d[i];
    }

    for(int i=0;i<N;i++) {
        printf("%.2f ",x[i]);
    }

    printf("\n");

    return 0;
}

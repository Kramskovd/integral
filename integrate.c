#include "integrate.h"

double integrateN(func_t f, double a, double b, int n){
    int i;
    double sum;
    double h, xi, k1, k2;

    h = (b-a)/n;

    sum = 0.0;
    k1 = 0.5*((sqrt(3)-3)/3)*h;
    k2 = -0.5*((sqrt(3)+3)/3)*h;

    for(i = 1; i <= n; i++){
        xi = a+i*h;
        sum +=  f( xi + k1 ) + f( xi + k2 );
    }

    return sum*h*0.5;
}

int integrate(func_t f, double a, double b, double e, double *r){
    double i1, i2, d;
    int i;
    int n;

    n = 2;
    i1 = integrateN(f, a, b, n);
    for(i = 2; i < 31; i++){
        n *= 2;
        i2 = integrateN(f, a, b, n);
        d = (i2-i1)/0.9375;
        if(fabs(d) < e){
            *r = i1 + d;
            return 0;
        }

        i1 = i2;
    }
    return -1;
}

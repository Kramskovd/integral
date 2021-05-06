#include "integrate.h"

double f1(double x){
    return 2*x;
}

double f2(double x){
    return 3*(x*x);
}

double f3(double x){
    return 4*(x*x*x);
}
double f4(double x){
    return 5*(x*x*x*x);
}
double f5(double x){
    return 1/(1+x*x);
}

double f6(double x){
    return sqrt(1-x*x);
}
double f7(double x){
    return 2*exp(2*x);
}
double f8(double x){
    return log(x+1)/(x*x+1);
}
double f9(double x){
    return x*x/(1+exp(sin(x)));
}
#ifndef _INTEGRATE_H_
#define _INTEGRATE_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_E
#define M_E 2.7182818284590452354
#endif

#ifndef M_LN2
#define M_LN2 0.69314718055994530942
#endif

typedef double(*func_t)(double);
double integrateN(func_t f, double a, double b, int n);
int integrate(func_t f, double a, double b, double e, double *r);
void print (double res);
void printerr (const char *s);
int toInt(const char *str, int *res);
int toDouble(const char *str, double *res);


double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
double f5(double x);
double f6(double x);
double f7(double x);
double f8(double x);
double f9(double x);

#endif
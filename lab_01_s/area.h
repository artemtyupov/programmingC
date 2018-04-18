#ifndef AREA_H
#define AREA_H
#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef double (*func_t)(double);
typedef double (*method_t)(double, double, int, func_t);


double resh(double a, double b, double eps, double (*f)(double));
double integral(double a, double b, double eps, method_t meth, func_t func);
double trapezium(double a, double b, int n, func_t func);

#endif // AREA_H

#include "area.h"

double f11(double x)
{
    return exp(-x+2);
}

double f22(double x)
{
    return 3*x+2;
}

double f33(double x)
{
    return exp(x);
}

double integral(double a, double b, double eps, method_t meth, func_t func)
{
    assert(a < b);
    assert(0 < eps && eps < 1);
    assert(meth);
    assert(func);

    int n = 10;
    double prev, cur = meth(a, b, n, func);

    do
    {
        prev = cur;

        n *= 2;
        cur = meth(a, b, n, func);
    }
    while (fabs((cur - prev) / cur) > eps);

    return cur;
}

double trapezium(double a, double b, int n, func_t func)
{
    assert(a < b);
    assert(n > 1);
    assert(func);

    double h = (b - a) / (n - 1);
    double x = a + h;
    double s = (func(a) + func(b)) / 2.0;

    for (int i = 1; i < n - 1; i++)
    {
        s += func(x);
        x += h;
    }

    return s * h;
}

double resh(double a, double b, double eps, double (*f)(double))
{
    double c;
    while (b - a > eps)
    {
        c = (a + b) / 2;
        if (f(b)*f(c) < 0)
            a = c;
        else
            b = c;
    }
    return (a+b) / 2;
}

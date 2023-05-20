#include <stdlib.h>
#include <stdio.h>

const double h = 0.1;

struct data
{
    int a, b;
    double h;
    double *value;
};

double fun (double x, double y)
{
    return x + y;
}

double Runge_Kutta (double x, double y)
{
    double k1, k2, k3, k4;

    k1 = h * fun (x, y);
    k2 = h * fun (x + h / 2, y + k1 / 2);
    k3 = h * fun (x + h / 2, y + k2 / 2);
    k4 = h * fun (x + h, y + k3);

    return y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}


int main (int argc, char* argv[])
{
    printf("%f %f\n", Runge_Kutta(0, 1), Runge_Kutta(h, Runge_Kutta(0, 1)));

    return 0;
}
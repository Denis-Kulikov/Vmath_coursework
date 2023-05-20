#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

const double h = 0.1;

// const day = 90;
#define DAY 90
#define N 2798170


const double aE     = 0.999;
const double aI     = 0.999;
const double ck     = 0.042;
const double ro     = 0.952;
const double beta   = 0.999;
const double myu    = 0.0188;

enum
{
    S,
    E,
    I,
    R,
    D
};


double Runge_Kutta (double x, double s, double e, double i, double r, double d)
{
    double k[5][4] = {0};



    /*
    k1 = h * fun (x, y);
    k2 = h * fun (x + h / 2, y + k1 / 2);
    k3 = h * fun (x + h / 2, y + k2 / 2);
    k4 = h * fun (x + h, y + k3);

    return y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    */
   return 0;
}


int main (int argc, char* argv[])
{
    double data[5][DAY + 1];

    data[E][0] = 99; 
    data[R][0] = 24; 
    data[I][0] = 0; 
    data[D][0] = 0; 
    data[S][0] = N - data[E][0] - data[R][0]; 

    // printf("%f %f\n", Runge_Kutta(0, 1), Runge_Kutta(h, Runge_Kutta(0, 1)));

    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

const double h = 0.1;

#define DAY 90
#define N 2798170


enum
{
    S,
    E,
    I,
    R,
    D
};


double Runge_Kutta (double s, double e, double i, double r, double d, double data[5])
{
    double k[4][5] = {0};

    k[0][S] = h * fun_s (s, e, i);
    k[0][E] = h * fun_e (s, e, i);
    k[0][I] = h * fun_i (e, i);
    k[0][R] = h * fun_r (e, i);
    k[0][D] = h * fun_d (i);

    k[1][S] = h * fun_s (s + k[0][S] / 2, e + k[0][E] / 2, i + k[0][I] / 2);
    k[1][E] = h * fun_e (s + k[0][S] / 2, e + k[0][E] / 2, i + k[0][I] / 2);
    k[1][I] = h * fun_i (e + k[0][E] / 2, i + k[0][I] / 2);
    k[1][R] = h * fun_r (e + k[0][E] / 2, i + k[0][I] / 2);
    k[1][D] = h * fun_d (i + k[0][I] / 2);

    k[2][S] = h * fun_s (s + k[1][S] / 2, e + k[1][E] / 2, i + k[1][I] / 2);
    k[2][E] = h * fun_e (s + k[1][S] / 2, e + k[1][E] / 2, i + k[1][I] / 2);
    k[2][I] = h * fun_i (e + k[1][E] / 2, i + k[1][I] / 2);
    k[2][R] = h * fun_r (e + k[1][E] / 2, i + k[1][I] / 2);
    k[2][D] = h * fun_d (i + k[1][I] / 2);

    k[3][S] = h * fun_s (s + k[2][S], e + k[2][E], i + k[2][I]);
    k[3][E] = h * fun_e (s + k[2][S], e + k[2][E], i + k[2][I]);
    k[3][I] = h * fun_i (e + k[2][E], i + k[2][I]);
    k[3][R] = h * fun_r (e + k[2][E], i + k[2][I]);
    k[3][D] = h * fun_d (i + k[2][I]);

    data[S] = s + (k[0][S] + 2 * k[1][S] + 2 * k[2][S] + k[3][S]) / 6;
    data[E] = e + (k[0][E] + 2 * k[1][E] + 2 * k[2][E] + k[3][E]) / 6;
    data[I] = i + (k[0][I] + 2 * k[1][I] + 2 * k[2][I] + k[3][I]) / 6;
    data[R] = r + (k[0][R] + 2 * k[1][R] + 2 * k[2][R] + k[3][R]) / 6;
    data[D] = d + (k[0][D] + 2 * k[1][D] + 2 * k[2][D] + k[3][D]) / 6;

   return 0;
}


int main (int argc, char* argv[])
{
    double data[DAY + 1][5], *data_ = data[DAY];
    FILE* fd = fopen("data/result.txt", "w");
    if (fd == NULL)
        return -1;
        
    data[0][E] = 99; 
    data[0][R] = 24; 
    data[0][I] = 0; 
    data[0][D] = 0; 
    data[0][S] = N - data[0][E] - data[0][R]; 

    Runge_Kutta(data[0][S], data[0][E], data[0][I], data[0][R], data[0][D], data_);

    printf("S\t\tE\tI\tR\tD\n");
    for (int i = 0; i < DAY; i++) {
        Runge_Kutta(data[i][S], data[i][E], data[i][I], data[i][R], data[i][D], data[i + 1]);
        if (i % 10 == 0);
            // printf("%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t\n", data[i][S], data[i][E], data[i][I], data[i][R], data[i][D], data[i + 1]);
        fprintf(fd, "%d\t%f\n", i + 1, (data[i + 1][E] + data[i + 1][I] + data[i + 1][R]) - 
                                       (data[i][E] + data[i][I] + data[i][R]));
    }

    for (int i = 0; i < 5; i++)
        printf("%0.2f\t", data_[i]);
    printf("\n");

    return 0;
}
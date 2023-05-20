#define N 2798170

const double aE     = 0.999;
const double aI     = 0.999;
const double ck     = 0.042;
const double ro     = 0.952;
const double beta   = 0.999;
const double myu    = 0.0188;
const double ciso   = 0.0;


double fun_s (double s, double e, double i)
{
    return -((aI * s * i) + (aE * s * e)) / N;
}

double fun_e (double s, double e, double i)
{
    return ((aI * s * i) + (aE * s * e)) / N - (ck + ro) * e;
}

double fun_i (double e, double i)
{
    return ck * e - beta * i - myu * i;
}

double fun_r (double e, double y, double i)
{
    return beta * i + ro * e ;
}

double fun_d (double i)
{
    return myu * i;
}
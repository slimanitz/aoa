#include "kernel.h"

float baseline(unsigned n, double **a, double *b)
{
    unsigned i, j;
    float s = 0.0;

    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++)
            s += a[i][j] * b[j];
    return s;
}
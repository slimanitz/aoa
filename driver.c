#include <stdio.h>
#include "kernel.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {

        printf("Nombre d'argument invalide\n");
        return 1;
    }

    const int n = atoi(argv[1]);
    const char *file_name = argv[2];

    double **a = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
        a[i] = (double *)malloc(n * sizeof(double));
    double *b = malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            a[i][j] = (double)rand() / RAND_MAX;
        }
    }

    for (int j = 0; j < n; j++)
    {
        b[j] = (double)rand() / RAND_MAX;
    }

    float s = baseline(n, a, b);

    FILE *out_file = fopen(file_name, "w"); // write only
    fprintf(out_file, "%f", s);             // write to file

    for (int i = 0; i < n; i++)
    {
        free(a[n]);
    }
    free(a);

    free(b);

    return 0;
}

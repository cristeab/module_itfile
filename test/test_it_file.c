#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "it_file.h"

#define PI 3.1415926535
#define LENGTH 100
#define OMEGA (PI/6.0)
#define FILE_NAME "test_it_file.it"
#define VAR_NAME "signal"

int main(void)
{
    double *signal = malloc(LENGTH*sizeof(*signal));
    double *ref_signal = malloc(LENGTH*sizeof(*ref_signal));
    int n;
    int out = EXIT_FAILURE;

    if ((NULL == signal) || (NULL == ref_signal))
    {
        printf("Cannot allocate memory\n");
        goto fail;
    }
    for (n = 0; n < LENGTH; ++n)
    {
        signal[n] = sin(OMEGA*n);
    }

    if (EXIT_SUCCESS != it_file_open(FILE_NAME))
    {
        printf("Cannot open file\n");
        goto fail;
    }
    if (EXIT_SUCCESS != it_file_write_double(VAR_NAME, signal, LENGTH))
    {
        printf("Cannot write variable\n");
        goto fail;
    }
    if ((EXIT_SUCCESS != it_file_read_double(VAR_NAME, ref_signal, &n)) || (LENGTH != n))
    {
        printf("Cannot read variable\n");
        goto fail;
    }
    for (n = 0; n < LENGTH; ++n)
    {
        if (signal[n] != ref_signal[n])
        {
            printf("Values don't match\ni");
            goto fail;
        }
    }

    printf("SUCCESS\n");
    out = EXIT_SUCCESS;
fail:
    free(signal);
    free(ref_signal);
    return out;
}

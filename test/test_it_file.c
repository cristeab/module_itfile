#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "it_file.h"

#define PI 3.1415926535
#define LENGTH 100
#define OMEGA (PI/6.0)
#define FILE_NAME "test_it_file.it"
#define VAR_NAME "signal"
#define VAR_NAME_I "signal_i"

int main(void)
{
    double *signal = malloc(LENGTH*sizeof(*signal));
    double *ref_signal = malloc(LENGTH*sizeof(*ref_signal));
    int *signal_i = malloc(LENGTH*sizeof(*signal_i));
    int *ref_signal_i = malloc(LENGTH*sizeof(*ref_signal_i));
    int n;
    int out = EXIT_FAILURE;

    /* check inputs */
    if (EXIT_FAILURE != it_file_open(NULL))
    {
        printf("Should not open file\n");
        goto fail;
    }

    /* generate signals */
    if ((NULL == signal) || (NULL == ref_signal) ||
            (NULL == signal_i) || (NULL == ref_signal_i))
    {
        printf("Cannot allocate memory\n");
        goto fail;
    }
    for (n = 0; n < LENGTH; ++n)
    {
        signal[n] = sin(OMEGA*n);
        signal_i[n] = 0;
    }
    signal_i[0] = 1;

    /* functional test */
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
    if (EXIT_SUCCESS != it_file_write_int(VAR_NAME_I, signal_i, LENGTH))
    {
        printf("Cannot write variable\n");
        goto fail;
    }
    if ((EXIT_SUCCESS != it_file_read_double(VAR_NAME, ref_signal, &n)) || (LENGTH != n))
    {
        printf("Cannot read variable\n");
        goto fail;
    }
    if ((EXIT_SUCCESS != it_file_read_int(VAR_NAME_I, ref_signal_i, &n)) || (LENGTH != n))
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
        if (signal_i[n] != ref_signal_i[n])
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
    free(signal_i);
    free(ref_signal_i);
    return out;
}

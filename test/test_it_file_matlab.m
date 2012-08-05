clear all
clc

x_int = 1:10;
x_scalar = 11;
x_double = x_int/20;
x_scalar_dbl = 3.1415;

x_int = int32(x_int);
x_scalar = int32(x_scalar);

itsave('test_it_file_matlab.it', x_int, x_scalar, x_double, x_scalar_dbl);

#include "it_file.h"
#include "itfile.h"/* IT++ implementation */
#include <cstdlib>

static
itpp::it_file file;

int it_file_open(const char *const file_name)
{
    file.open(file_name);
    return itpp::exist(file_name)?EXIT_SUCCESS:EXIT_FAILURE;
}

template<class T>
static
int it_file_read_template(const char *const name, T *const data, int *const data_size)
{
    itpp::Vec<T> out;
    file >> itpp::Name(name) >> out;
    if (*data_size < out.size())
    {
        *data_size = out.size();
        return EXIT_FAILURE;
    }
    *data_size = out.size();
    memcpy(data, out._data(), out.size()*sizeof(*data));
    return EXIT_SUCCESS;
}

template<class T>
static
int it_file_write_template(const char *const name, const T *const data, int data_size)
{
    itpp::Vec<T> out(data_size);
    memcpy(out._data(), data, data_size*sizeof(*data));
    file << itpp::Name(name) << out;
    file.flush();
    return EXIT_SUCCESS;
}

int it_file_read_double(const char *const name, double *const data, int *const data_size)
{
    return it_file_read_template<>(name, data, data_size);
}

int it_file_write_double(const char *const name, const double *const data, int data_size)
{
    return it_file_write_template<>(name, data, data_size);
}

int it_file_read_int(const char *const name, int *const data, int *const data_size)
{ 
    return it_file_read_template<>(name, data, data_size);
}

int it_file_write_int(const char *const name, const int *const data, int data_size)
{
    return it_file_write_template<>(name, data, data_size);
}

void it_file_close(void)
{
    file.close();
}


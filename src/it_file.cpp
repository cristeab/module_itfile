#include "it_file.h"
#include "itfile.h"/* IT++ implementation */
#include <cstdlib>

static
itpp::it_file file;
static
bool ro_flag = false;

int it_file_open(const char *const file_name)
{
    if (NULL == file_name)
    {
        return EXIT_FAILURE;
    }
    file.open(file_name);
    return itpp::exist(file_name)?EXIT_SUCCESS:EXIT_FAILURE;
}

int it_file_open_ro(const char *const file_name)
{
    if ((NULL == file_name) || (false == itpp::exist(file_name)))
    {
        return EXIT_FAILURE;
    }
    file.itpp::it_ifile::open(file_name);
    ro_flag = true;
    return EXIT_SUCCESS;
}

template<class T>
static
int it_file_read_template(const char *const name, T *const data, int *const data_size)
{
    itpp::Vec<T> out;

    if ((NULL == name) || (NULL == data) || (NULL == data_size))
    {
        return EXIT_FAILURE;
    }

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
    if ((NULL == name) || (NULL == data) || (true == ro_flag))
    {
        return EXIT_FAILURE;
    }
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


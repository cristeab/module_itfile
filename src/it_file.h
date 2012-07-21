#ifndef IT_FILE_H_
#define IT_FILE_H_

extern "C" {

int it_file_open(const char *const file_name);
int it_file_read_double(const char *const name, double *const data, int *const data_size);
int it_file_write_double(const char *const name, const double *const data, int data_size);
int it_file_read_int(const char *const name, int *const data, int *const data_size);
int it_file_write_int(const char *const name, const int *const data, int data_size);
void it_file_close(void);

}

#endif


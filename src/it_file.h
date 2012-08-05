#ifndef IT_FILE_H_
#define IT_FILE_H_

#ifdef _MSC_VER
#define DllExport   __declspec( dllexport )
#else
#define DllExport
#endif

#ifdef __cplusplus
extern "C" {
#endif

DllExport int it_file_open(const char *const file_name);
DllExport int it_file_open_ro(const char *const file_name);
DllExport int it_file_read_double(const char *const name, double *const data, int *const data_size);
DllExport int it_file_write_double(const char *const name, const double *const data, int data_size);
DllExport int it_file_read_int(const char *const name, int *const data, int *const data_size);
DllExport int it_file_write_int(const char *const name, const int *const data, int data_size);
DllExport void it_file_close(void);

#ifdef __cplusplus
}
#endif

#endif


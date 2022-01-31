#ifndef DIN_LIB
#define DIN_LIB

#ifndef EXPORT_LIB
#define LIB_DLL __declspec(dllexport)
#else
#define LIB_DLL __declspec(dllimport)
#endif

#define LIB_DECL __cdecl

#include <stdio.h>

LIB_DLL int LIB_DECL file_size(FILE *f, size_t *size);

LIB_DLL int LIB_DECL file_read(FILE *f, int *pstart, int *pend);

LIB_DLL void LIB_DECL file_write(FILE *f, int *pstart, int *pend);

#endif
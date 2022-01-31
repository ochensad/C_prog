#include "my_file.h"
#include "student.h"
#include "struct.h"

int main(int avgc, char **avgv)
{
  FILE *f;

  if (avgc != 2)
    return EXIT_INVALID_ARGV;

  f = fopen(avgv[1], "rb+");

  if (f == NULL)
      return EXIT_NO_FILE;

  delete_st(f);
  fclose(f);
  return OK;
}
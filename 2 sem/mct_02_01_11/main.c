#include "my_file.h"

int main(int avgc, char **avgv)
{
  FILE *f;
  if (avgc != 3)
    return EXIT_INVALID_ARGV;
  
  f = fopen(avgv[2], "r");

  if (f == NULL)
      return EXIT_NO_FILE;
  
  make_a_i(f,avgv[1]);
  fclose(f);
  return OK;
}
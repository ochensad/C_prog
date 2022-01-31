#include "my_file.h"

int main(int avgc, char **avgv)
{
  FILE *f;

  char str1[MAX_LEN + 1];
  if (avgc != 3)
    return EXIT_INVALID_ARGV;
  
  f = fopen(avgv[1], "r");

  if (f == NULL)
      return EXIT_NO_FILE;
      
  while (fscanf(f, "%s", str1) == 1)
  {
      if (a_i(avgv[2], str1) == YES)
          printf("%s\n", str1);
  }
  fclose(f);
  return OK;
}
#include "my_file.h"

int del_st(char *str_1, char *str_2)
{
  for (size_t i = 0; str_2[i] != '\0'; i++)
  {
    for (size_t j = 0; str_1[j] != '\0'; j++)
    {
      if (str_2[i]==str_1[j])
      {
        size_t k = j;
        while (str_1[k] != '\0')
        {
          str_1[k] = str_1[k + 1];
          k++;
        }
      }
    }
  }
  return OK;
}
int find_pol(char *s)
{
  size_t i = strlen(s) - 1;
  char left[80];
  char right[80];
  size_t k = 0;
  if (i != 0)
  {
    for (size_t j = 0; j <= i; j++)
    {
      if (j < i / 2)
      {
        left[j] = s[j];
      }
      else
      {
        right[k] = s[j];
        k++;
      }
    }
  }
  return OK;
}
int make_a_i(FILE *f, char *s)
{
  char st[80];
  while(fgets(st, sizeof(st), f) != NULL)
  {
    del_st(st,s);
    find_pol(st);
  }
  return OK;
}

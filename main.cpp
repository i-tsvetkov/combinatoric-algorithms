#include <stdlib.h>
#include <string.h>
#include "cartesian.h"
#include "combination.h"
#include "variations.h"

int compr(const void *a, const void *b)
{
  return *(char*) a - *(char*) b;
}

char* sort(char *str)
{
  qsort(str, strlen(str), sizeof(char), compr);
  return str;
}

int main(int argc, char **argv)
{

  if (argc < 3)
    return 1;

  sort(argv[2]);
  int len = strlen(argv[2]);
  char *output = (char*) malloc(len + 1);
  output[len] = '\0';

  /* permutations without repetition */
  if (strcmp("perm", argv[1]) == 0)
  {
    variations(len, len, argv[2], output);
  }

  /* permutations with repetition */
  if (strcmp("perm-r", argv[1]) == 0)
  {
    variations_r(len, len, argv[2], output);
  }

  if (argc < 4)
  {
    free(output);
    return 0;
  }

  int k = atoi(argv[3]);

  /* cartesian power */
  if (strcmp("cart", argv[1]) == 0)
  {
    product(k, len, argv[2], output);
  }

  /* variations without repetition */
  if (strcmp("var", argv[1]) == 0)
  {
    variations(k, len, argv[2], output);
  }

  /* variations with repetition */
  if (strcmp("var-r", argv[1]) == 0)
  {
    variations_r(k, len, argv[2], output);
  }

  /* combinations without repetition */
  if (strcmp("comb", argv[1]) == 0)
  {
    combinations(k, len, argv[2], output);
  }

  /* combination with repetition */
  if (strcmp("comb-r", argv[1]) == 0)
  {
    combinations_r(k, len, argv[2], output);
  }

  free(output);

  return 0;
}


#include <cstdio>

void combinations(int k, int n, char in[], char out[], int j = 0, int p = 0)
{
  for (int i = j; i < n; i++)
  {
    out[p] = in[i];
    if (k > 1)
      combinations(k - 1, n, in, out, i + 1, p + 1);
    else
      puts(out);
  }
}

void combinations_r(int k, int n, char in[], char out[], int j = 0, int p = 0)
{
  for (int i = j; i < n; i++)
  {
    out[p] = in[i];
    if (k > 1)
      combinations_r(k - 1, n, in, out, i, p + 1);
    else
      puts(out);
  }
}


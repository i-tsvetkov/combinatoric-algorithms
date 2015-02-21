#include <cstdio>

void product(int k, int n, char in[], char out[], int p = 0)
{
  for (int i = 0; i < n; i++)
  {
    out[p] = in[i];
    if (k > 1)
      product(k - 1, n, in, out, p + 1);
    else
      puts(out);
  }
}


#include <cstdio>

char *remove(char e, int n, char in[], char out[])
{
  bool b = false;
  for (int i = 0, p = 0; i < n; i++)
    if (in[i] != e || b)
      out[p++] = in[i];
    else
      b = true;
  return out;
}

void variations(int k, int n, char in[], char out[], int p = 0)
{
  for (int i = 0; i < n; i++)
  {
    out[p] = in[i];
    if (k > 1)
    {
      char next[n - 1];
      variations(k - 1, n - 1, remove(in[i], n, in, next), out, p + 1);
    }
    else
      puts(out);
  }
}

void variations_r(int k, int n, char in[], char out[], int p = 0)
{
  for (int i = 0; i < n; i++)
  {
    if ((i == 0) ? true : (in[i] != in[i - 1]))
    {
      out[p] = in[i];
      if (k > 1)
      {
        char next[n - 1];
        variations_r(k - 1, n - 1, remove(in[i], n, in, next), out, p + 1);
      }
      else
        puts(out);
    }
  }
}


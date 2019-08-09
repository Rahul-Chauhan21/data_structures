#include<stdio.h>
#include<stdlib.h>
int
gcd (int a, int b)
{
  if (b == 0)
    return a;
  return gcd (b, a % b);
}

void
Array_rotate_left (int a[], int n, int k)
{
  int d = -1, i, j, temp;
  for (int i = 0; i < gcd (n, k); i++)
    {
      j = i;
      temp = a[i];
      while (1)
	{
	  d = (k + j) % n;
	  if (d == i)
	    break;
	  a[j] = a[d];
	  j = d;
	}
      a[j] = temp;
    }
}

int
main (int argc, const char *argv[])
{
  int n = argc - 2;
  int r = atoi (argv[argc - 1]);
  int j = 0;
  int arr[n];
  for (int i = 0; i < argc - 1; i++)
    {
      if (i == 0)
	continue;
      arr[j++] = atoi (argv[i]);
    }
  Array_rotate_left (arr, n, r);
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", arr[i]);
    }
  return 0;
}


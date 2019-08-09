#include <stdio.h>
#include <stdlib.h>

int
main (int argc, const char *argv[])
{
  int n = argc - 1, c = 0, c1, j = 0;
  int a[n];
  int a1[n];

  for (int i = 0; i < argc; i++)
    {
      if (i == 0)
	continue;
      a[j++] = atoi (argv[i]);
    }
  //finding pivot point
  int temp = a[0];
  for (int i = 1; i < n; i++)
    {
      if (a[i] > temp)
	{
	  temp = a[i];
	  c = i;
	}

    }
  printf ("pivot at index %d\n", c);

  j = 0;
  c1 = c + 1;
//printf("%d\n",c1);
  for (int i = 0; i < n; i++)
    {
      if (c1 + i < n)
	{
	  a1[i] = a[c1 + i];
	}
      else
	a1[i] = a[j++];
    }
  //print array;
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", a1[i]);
    }
  return 0;
}

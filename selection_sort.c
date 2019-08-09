#include<stdio.h>
#include<stdlib.h>
void
swap (int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int
main (int argc, const char *argv[])
{
  int n = argc - 1, j = 0;
  int arr[n];

  for (int i = 0; i < argc; i++)
    {
      if (i == 0)
	continue;
      arr[j++] = atoi (argv[i]);
    }
  int index;
  for (int i = 0; i < n; i++)
    {
      index = i;
      for (int j = i + 1; j < n; j++)
	{
	  if (arr[j] < arr[index])
	    index = j;
	}
      swap (&arr[index], &arr[i]);
    }
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", arr[i]);
    }
  return 0;
}


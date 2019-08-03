#include<stdio.h>
#include<stdlib.h>
void array_leftrotate (int *arr, int size);
void array_rightrotate (int *arr, int size);
void
array_leftcounter (int *arr, int size, int n1)
{
  for (int i = 0; i < n1; i++)
    array_leftrotate (arr, size);
}

void
array_rightcounter (int *arr, int size, int n1)
{
  for (int i = 0; i < n1; i++)
    array_rightrotate (arr, size);
}

void
array_leftrotate (int *arr, int size)
{
  int temp = arr[0];		// 1 2 3
  for (int i = 0; i < size - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
  arr[size - 1] = temp;
}

void
array_rightrotate (int *arr, int size)
{
  int temp = arr[size - 1];	// 1 2 3 4 // 4 1 2 3
  for (int i = size - 1; i >= (size / 2); i--)
    {
      arr[i] = arr[i - 1];
    }
  arr[(size / 2)] = temp;
}

int
main (int argc, const char *argv[])
{
  int n = argc - 3;
  int j = 0;
  int arr[n];
  for (int i = 0; i < argc-2; i++)
    {
      if (i == 0)
	continue;
      arr[j++] = atoi (argv[i]);
    }
  int l = n / 2;
 int nl=atoi(argv[argc-2]);
 int nr=atoi(argv[argc-1]);
  
  array_leftcounter (arr, l, nl);
  array_rightcounter (arr, n, nr);
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", arr[i]);
    }
  return 0;
}


//traversing using pointers in an array
#include<stdio.h>
#include<stdlib.h>
int main(int argc,const char *argv[])
{
        int a=argc-1;
        int i,j=1;
        int arr[argc-1];
        for(i=0;i<argc-1;i++)
        {
                arr[i]=atoi(argv[j]);           //input an array
                j++;
        }
       int *ptr=&arr[argc-2];
        for(i=0;i<a;i++)
        {
		printf("%d",*(ptr-i));
	}
	return 0;
}

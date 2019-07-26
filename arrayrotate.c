//right rotation by n in an array
#include<stdio.h>
#include<stdlib.h>
int main(int argc,const char * argv[])
{
	int a=argc-1;
	int i,j=1;
	int arr[argc-1];
	for(i=0;i<argc-1;i++)
	{
		arr[i]=atoi(argv[j]);		//input an array
		j++;
	}
	int n=3;   //rotation by n numbers
	for(i=0;i<n;i++)
	{
		int temp=arr[argc-2];
		int k;
		for(k=argc-2;k>0;k--)
		{
			arr[k]=arr[k-1];
		}
		arr[0]=temp;
	}
	for(i=0;i<argc-1;i++)
	{
		printf("%d",arr[i]);
	}
	return 0;
}

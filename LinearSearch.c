#include<stdio.h>
#include<stdlib.h>
int main()
{
int n;
printf("Enter the number of elements\n");
scanf("%d",&n);
int x;
int *arr;
arr=(int*)malloc(n*sizeof(int));
printf("Enter elements\n");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

printf("Enter the element to be searched");
scanf("%d",&x);
	for(int i=0;i<n;i++)
	{
	if(arr[i]==x)
	printf("Element found at index %d",i);	
	}
return 0;	
}	

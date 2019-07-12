#include<stdio.h>
#include<stdlib.h>
int main(void)
{
 int n;
 printf("Enter the number of elements\n");
 scanf("%d",&n);
 int *arr;
 arr=(int*)malloc(n*sizeof(int));
 printf("Enter the elements\n");
 for(int i=0;i<n;i++)
 {
 scanf("%d",&arr[i]);
 }
 int x;
 printf("Enter the element to be searched\n");
 scanf("%d",&x);
 for(int i=0;i<n;i++)
 {
   for(int j=i+1;j<n;j++)
   {
   if(arr[i]>arr[j])
   {
   int temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
   }
   }
 }
 int l=0;
 int r=n-1;
 int mid=0;
 int findex=-1;
	 while(l<=r)
 	{
	 mid=(r+l)/2;
	 if(arr[mid]==x)
	 {	 
	 findex=mid;
	 break;
	 }
	 else if(arr[mid]>x)
	 r=mid-1;
	 else
	 l=mid+1;
	}
 if(findex!=-1)
 {
 printf("Element is present");
 }
 else
 {
 printf("Element not found");
 }
 return 0;
}

#include<stdio.h>
#include<stdlib.h>

void reverse(int *ptr,int l,int r)
{
 int temp;
 if(l>=r)
 return;
 temp=ptr[l];
 ptr[l]=ptr[r];
 ptr[r]=temp;
 reverse(ptr,l+1,r-1);
}
void Arrange(int *ptr,int n)
{

}
int main(int argc, const char* argv[])
{
	int j=0;
	int arr[argc-1];
	for(int i=0;i<argc;i++)
	{
	if(i==0)continue;
	arr[j++]=atoi(argv[i]);	
	}

int n=argc-1;
// Iterative approach
/*(for(int i=0;i<n/2;i++)
{
int temp=0;
temp=arr[n-1-i];
arr[n-1-i]=arr[i];
arr[i]=temp;
}
*/
reverse(arr,0,n-1);
for(int i=0;i<n;i++)
{
printf("%d ",arr[i]);
}
// rearrange negative and positive numbers with zeroes in the front
Arrange(arr,n);
return 0;
}

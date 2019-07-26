#include <stdio.h>
#include <stdlib.h>
// 6 1 2 3 4 5
// 3 4 5 6 1 2 
int binary_search(int arr[],int low,int high,int num)
{
    if(low>high)
    return -1;
    int mid=low+(high-low)/2;
    if(arr[mid]==num)
    return mid;
    if(arr[low]<=arr[mid])
	{
	 if(num>=arr[low]&&num<=arr[mid])
	   return binary_search(arr,low,mid-1,num);
		return binary_search(arr,mid+1,high,num);
	}
    if(num>=arr[mid+1]&&num<=arr[high])
	return binary_search(arr,mid+1,high,num);
		return binary_search(arr,low,mid-1,num);
}
	
	

int main(int argc,const char* argv[])
{
    int n=argc-2;
    int j=0;
    int arr[n];
    int num=atoi(argv[argc-1]);
    for(int i=0;i<=argc-1;i++)
        {
    	if(i==0)continue;
        arr[j++]=atoi(argv[i]);
	}
    int result=binary_search(arr,0,n-1,num);
    if(result==-1)
    printf("Num not found");
    else
    printf("Num found at index %d",result);
    return 0;
}

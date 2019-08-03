#include<stdio.h>
#include<stdlib.h>
#define max 1000
int hash[max+1][2];
void insert(int arr[],int n){
 for(int i=0;i<n;i++){
	if(arr[i]>=0)
		hash[arr[i]][0]=1;
	else
		hash[abs(arr[i])][1]=1;
 }
}
int search(int x){
	if(x>=0)
	{
	 if(hash[x][0]==1)
	 return 1;
	 else return -1;	
	}
	else
	{
	if(hash[abs(x)][1]==1)
		return 1;	
	else return -1;
	}
}
int main(int argc,const char* argv[]){

int n=argc-2;
int arr[n];
int j=0;

	for(int i=0;i<argc-1;i++)
	{
	 if(i==0) continue;
	 arr[j++]=atoi(argv[i]);
	}
insert(arr,n);
int x=atoi(argv[argc-1]);

	if(search(x)==-1)
	printf("Not found");
	else
	printf("Found");

return 0;
}

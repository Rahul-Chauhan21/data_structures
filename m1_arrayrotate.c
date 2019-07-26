#include<stdio.h>
#include<stdlib.h>
int main(int argc,const char* argv[]){
int arr[argc-2];
int j=0;
 for(int i=0;i<=argc-1;i++)
	{
	if(i==0)continue;
	arr[j++]=atoi(argv[i]);
	}
 int size=argc-2;
 int num=atoi(argv[argc-1]);
 if(num>size)
 {
 num%=size;
 }
 printf("size of array:%d\nnumber of rotations:%d\n",size,num);
 int temp[num];
 for(int i=0;i<num;i++)
 {
 temp[i]=arr[size-num+i];
 }

 
 for(int i=size-num+1;i>=0;i--)
	{
	arr[i+num]=arr[i];	
 	}
 
 for(int i=0;i<num;i++)
 {
 arr[i]=temp[i];
 }
 for(int i=0;i<size;i++)
 {
 printf("%d ",arr[i]);
 }
 return 0;
}

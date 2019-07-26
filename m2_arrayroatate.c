#include<stdio.h>
#include<stdlib.h>
void Array_rotate(int* arr, int size);
void Array_rcounter(int* arr,int size,int num)
 {
  for(int i=0;i<num;i++)
  Array_rotate(arr,size);
 }
void Array_rotate(int* arr,int size)
 {
  int temp=arr[size-1];
  for(int i=size-1;i>=0;i--)
  {
  arr[i]=arr[i-1];
  }
  arr[0]=temp;
 }

int main(int argc,const char* argv[])
 {
  int arr[argc-2];
  int size=argc-2;
  int num=atoi(argv[argc-1]);
  int j=0;
  for(int i=0;i<argc-1;i++)
  	{
  	if(i==0)continue;
	arr[j++]=atoi(argv[i]);
	}
  Array_rcounter(arr,size,num);
  for(int i=0;i<size;i++)
  {
  printf("%d ",arr[i]);
  }
  return 0;
 }

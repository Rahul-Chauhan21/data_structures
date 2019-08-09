
// C program for insertion sort 
#include <stdio.h> 
#include <stdlib.h> 
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
   
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  

int main(int argc,const char* argv[]) 
{ 
    int j=0,n=argc-1;
    int arr[n];
    
    for(int i=0;i<argc;i++)
	{
		if(i==0)continue;
		arr[j++]=atoi(argv[i]);
	}
  
    insertionSort(arr, n); 
    printArray(arr, n); 
  
    return 0; 
} 


#include <stdio.h>
#include <stdlib.h>

void reverse_algo(int* arr,int start,int end){
    while(start<end){
        int temp = *(arr+start);
        *(arr+start) = *(arr+end);
        *(arr+end) = temp;
        start++;
        end--;
    }
}

int main(int argc,const char* argv[]){
    int n,*arr,d;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    arr = (int*)malloc(n*sizeof(int)); // return a generic pointer and type cast to int*
    printf("Enter elements:\n");

        for(int i=0;i<n;i++){
            scanf("%d",arr+i);
        }
    printf("Number of right rotations:\n");
    scanf("%d",&d);
    d = d%n;
    if(d!=0){
    reverse_algo(arr,n-d,n-1);
    reverse_algo(arr,0,n-d-1);
    reverse_algo(arr,0,n-1);
    }
    for(int i=0;i<n;i++){
                printf("%d",*(arr+i));
            }
    free(arr);
    return 0;
}
